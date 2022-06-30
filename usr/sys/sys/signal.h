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

typedef struct {
	int	si_signo;		/* signal number */
	int	si_errno;		/* associated error # */
	int	si_code;		/* signal code (see below) */
	pid_t	si_pid;			/* sending process */
	int	si_status;		/* exit value */
	void	*si_addr;		/* faulting instruction */
} siginfo_t;

/*
 * Macro for converting a signal number to a mask.
 */
#define SIGMASK(n)	(1 << ((n) - 1))

/* codes for SIGILL */
#define ILL_ILLOPC	1	/* illegal opcode */
#define ILL_ILLOPN	2	/* illegal operand */
#define ILL_ILLADR	3	/* illegal addressing mode */
#define ILL_ILLTRP	4	/* illegal trap */
#define ILL_PRVOPC	5	/* priviledged opcode */
#define ILL_PRVREG	6	/* priviledged register */
#define ILL_COPROC	7	/* coprocessor error */
#define ILL_BADSTK	8	/* bad stack */

/* codes for SIGBUS */
#define BUS_ADRALN	1	/* invalid address alignment */
#define BUS_ADRERR	2	/* nonexistent physical address */
#define BUS_OBJERR	3	/* object-specific hardware error */

/* codes for SIGSEGV */
#define SEGV_MAPERR	1	/* address not mapped to object */
#define SEGV_ACCERR	2	/* inavlid perms for mapped object */

/* codes for SIGFPE */
#define FPE_INTOVF	1	/* integer overflow */
#define FPE_INTDIF	2	/* integer divide by zero */
#define FPE_FLTDIV	3	/* floating point divide by zero */
#define FPE_FLTOVF	4	/* floating point overflow */
#define FPE_FLTUND	5	/* floating point underflow */
#define FPE_FLTRES	6	/* floating point in-exact result */
#define FPE_FLTINV	7	/* invalid floating point operation */
#define FPE_FLTSUB	8	/* subscript out of range */
#define FPE_FLTIDO	9	/* input denormal operation */

/* codes for SIGTRAP */
#define TRAP_BRKPT	1	/* process breakpoint */
#define TRAP_TRACE	2	/* process trace trap */
#define TRAP_DTRACE	3	/* DTrace induced trap */
#define TRAP_CAP	4	/* capabilities protective trap */

/* codes for SIGPOLL */
#define POLL_IN		1	/* data input available */
#define POLL_OUT	2	/* output buffer(s) available */
#define POLL_MSG	3	/* input message available */
#define POLL_ERR	4	/* I/O error */
#define POLL_PRI	5	/* high priority input available */
#define POLL_HUP	6	/* hangup (device disconnected) */

#endif /* !_SYS_SIGNAL_H_ */
