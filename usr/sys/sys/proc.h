#ifndef _SYS_PROC_H_
#define _SYS_PROC_H_

#include <sys/types.h>
#include <sys/signal.h>
#include <sys/time.h>

#include <machine/types.h>
#include <machine/proc.h>
#include <machine/cpu.h>
#include <machine/frame.h>

#include <vm/vm.h>

/*
 * Runnable context from the point of view of the kernel.
 * Each thread is part of a process, who may have multiple
 * threads.
 */
struct thread {
	tid_t	td_tid;			/* unique identifier */
	void	*td_wchan;		/* waiting channel */
	int	td_cpu;			/* cpu running thread */
	int	td_errno;		/* error from syscall */
	QUEUE_ENTRY(struct thread) td_plist; /* list of threads in proc */
	QUEUE_ENTRY(struct thread) td_runq; /* run-queue entry */
	QUEUE_ENTRY(struct thread) td_slpq; /* sleep-queue entry */
	struct proc	td_proc;	/* owning process */
	struct sigque	td_sigq;	/* signal queue */
	struct mdthread	td_md;		/* machine-dependent data */
	struct trapframe *td_frame;	/* saved state upon trap */
	struct sigqueue	td_sigq;	/* signal queue */
	enum td_states {
		TDS_INACTIVE = 0,
		TDS_SLEEPING,
		TDS_RUNNING,
		TDS_READY,
	} td_state;
};

/*
 * Process structure.
 */
struct proc {
	pid_t	p_pid;			/* unique identifier */
	int	p_exit;			/* exit code */
	struct mdproc p_md;		/* machine-dependent data */
	struct sigqueue p_sigq;		/* signal queue */
	struct sigacts *p_sigacts;	/* signal actions */
	struct tty *p_ctty;		/* controlling terminal */
	struct vmspace *p_vmspace;	/* address map */
	struct inode *p_cwd;		/* current working directory */
	struct proc *p_pptr;		/* pointer to parent process */
	struct filedesc	ofile[NOFILE];	/* open files */
};

#endif /* !_SYS_PROC_H_ */
