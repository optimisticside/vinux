#ifndef _SYS_IOVEC_H_
#define _SYS_IOVEC_H_

#include <sys/types.h>

/*
 * An I/O vector stores the base-address and size of the vector to which
 * data should be placed.
 */
struct iovec {
	void	*iov_base;	/* base address */
	size_t	iov_size;	/* size of vector */
};

#endif /* !_SYS_IOVEC_H_ */
