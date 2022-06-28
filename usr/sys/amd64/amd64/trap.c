#include <sys/types.h>
#include <sys/print.h>
#include <sys/proc.h>

#include <machine/cpufunc.h>
#include <machine/frame.h>
#include <machine/flags.h>
#include <machine/trap.h>

/*
 * Called by placeholder interrupt handlers. Handles all non-device-related
 * interrupts like page faults.
 */
int trap(struct trapframe *frame) {
	struct ksiginfo *ksi;
	struct thread *td;
	struct proc *p;
	uint32_t type;
	int signo, ucode;

	td = curthread;
	p = td->td_proc;
	type = frame->tf_trapno;

	if (frame->tf_flags & FL_INTENA) {
		if (TF_USERMODE(frame)) {
			printf("%d %s: Trap %s with interrupts disabled at %x:%x\n",
				(long)p->p_pid, p->p_name, frame->tf_cs, frame->tf_rip);
		} else {
			printf("Kernel trap %d with interrupts disabled\n", type);

			/*
			 * Interrupts should not be enabled while we are holding
			 * a spinlock.
			 */
			if (td->td_mach->mc_nspinlock == 0)
				enable_intr();
		}
	}

	if (TF_USERMODE(frame)) {
		td->td_frame = frame;

		switch (type) {
		case T_PRIVINS:
			signo = SIGILL;
			ucode = ILL_PRVOPC;
			break;

		case T_BREAKPOINT:
			signo = SIGTRAP;
			ucode = TRAP_BRKPT;
			break;

		case T_TRACE:
			signo = SIGTRAP;
			ucode = TRAP_TRACE;
			break;

		case T_STACK:
		case T_SEGNPRES:
			signo = SIGBUS;
			ucode = BUS_ADDRERR;
			break;

		case T_ALIGN:
			signo = SIGBUS;
			ucode = BUS_ADRALN;
			break;

		case T_GENPROT:
		case T_TSS:
		case T_DOUBLE:
		default:
			signo = SIGBUS;
			ucode = BUS_OBJERR;
			break;

		case T_DIVIDE:
			signo = SIGFPE;
			ucode = FPE_INTDIV;
			break;

		case T_OFLOW:
			signo = SIGFPE;
			ucode = FPE_INTOVF;
			break;

		case T_BOUND:
			signo = SIGFPE;
			ucode = FPE_FLTSUB;
			break;
		}
	}
}
