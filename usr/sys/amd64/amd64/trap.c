#include <sys/types.h>
#include <sys/print.h>
#include <sys/proc.h>

#include <machine/frame.h>

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

}
