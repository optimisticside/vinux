#ifndef _SYS_MUTEX_H_
#define _SYS_MUTEX_H_

/*
 * This mutex can be used as a spin-lock or sleep-lock.
 */
struct mutex {
	int		mtx_lock;	/* whether the lock is held */
	struct cpu	*mtx_holder;	/* holding cpu */
};

#endif /* !_SYS_MUTEX_H_ */
