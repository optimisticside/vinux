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
	volatile int		mtx_lock;	/* lock state */
};

#endif /* !_SYS_MUTEX_H_ */
