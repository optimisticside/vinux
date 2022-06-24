#include <sys/types.h>
#include <sys/signal.h>
#include <sys/proc.h>

/*
 * Finds the thread to send a signal to for when we are only provided a
 * process to send the signal to.
 */
static struct thread *findtd(struct proc *p, int mask) {
	struct thread *td;

	if (curproc == p && (curthread->td_sigmask&mask))
		return curthread;
	/* TODO: go thru process's thread list and find it */
}

/*
 * If the current process has recieved a signal, return the signal number.
 */
int issignal(struct thread *td) {
	int signo, pending;
	struct proc *p;

	p = td->td_proc;
	/* TODO: Do this */
}

/*
 * Send a signal to a process. If the signal has an action then it is performed
 * by the target, so we add it to the queue of pending signals for that
 * process.
 */
void psignal(struct proc *p, struct thread *td, int signo) {
	struct sigqueue *sigq;
	struct sigactions *ps;
	int mask;

	if (signo == 0 || signo >= NSIG)
		panic("signal number");
	mask = SIGMASK(signo);
	if (td == NULL) {
		td = findtd(p, signo);
		sigq = &p->p_sigq;
	} else
		sigq = &td->td_sigq;
	
	mtx_lock(ps->sa_mtx);
	if (ps->ps_ignore & mask) {
		
	}
}
