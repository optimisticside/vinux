#ifndef _MACHINE_PROC_H_
#define _MACHINE_PROC_H_

/*
 * Machine-dependent data for threads.
 */
struct mdthread {
	int		md_nspinlock;	/* number of held spinlocks */
	register_t	md_flags;	/* flags saved upon intr disable */
};

#endif /* !_MACHINE_PROC_H_ */
