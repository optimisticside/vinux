#ifndef _SYS_QUEUE_H_
#define _SYS_QUEUE_H_

#define QUEUE_HEAD(name, type)						\
struct name {								\
	type *qh_first;							\
	type **qh_last;							\
}

#define QUEUE_ENTRY(type)						\
struct {								\
	type *qe_next;		/* next element */			\
	type **qe_prev;	/* address of last next element */		\
}

#define QUEUE_FOREACH(var, head)					\
for ((var) = (head)->qh_first; (var); (var) = QUEUE_NEXT(var))

#define QUEUE_REMOVE(head, entry)					\
do {									\
	/* TODO: Do this */						\
} while(0)

#endif /* _SYS_QUEUE_H_ */
