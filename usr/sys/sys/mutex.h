#ifndef _SYS_MUTEX_H_
#define _SYS_MUTEX_H_

#include <machine/param.h>

/*
 * Spin/sleep mutex implementation.
 *
 * All mutex implementations have a member called mtx_lock that stores
 * primitive locking-information specific to the os.
 *
 * TODO: Add lock_object to store lock-data
 */
struct mutex {
	struct lock_object	mtx_obj;	/* common lock properties */
	volatile int		mtx_lock;	/* lock state */
};

/*
 * Mutex types passed to mutex initialization routine.
 */
#define MTX_DEF		0x01	/* default (sleep) */
#define MTX_SPIN	0x02	/* spin lock */

#endif /* !_SYS_MUTEX_H_ */
