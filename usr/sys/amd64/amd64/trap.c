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
	struct thread *td;
	struct proc *p;
	uint32_t type;
	int signo;

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
				enable_irq();
		}
	}

	if (TF_USERMODE(frame)) {
		td->td_frame = frame;
	}
}
