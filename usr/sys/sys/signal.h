#ifndef _SYS_SIGNAL_H_
#define _SYS_SIGNAL_H_

/*
 * Each process and thread has its own signal queue to store any pending
 * signals it may have.
 */
struct sigqueue {
	struct proc	*sq_proc;	/* associated process */
	sigset_t	sq_pend;	/* pending signals */
};

/*
 * Macro for converting a signal number to a mask.
 */
#define SIGMASK(n)	(1 << ((n) - 1))

#endif /* !_SYS_SIGNAL_H_ */
