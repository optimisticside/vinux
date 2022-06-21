#ifndef _SYS_TYPES_H_
#define _SYS_TYPES_H_

#include <machine/types.h>

typedef uint32_t        pid_t;
typedef uint32_t        uid_t;
typedef uint32_t        gid_t;
typedef uint64_t        ino_t;

struct thread;
struct device;
struct inode;
struct mutex;
struct proc;
struct tty;

#endif /* !_SYS_TYPES_H_ */
