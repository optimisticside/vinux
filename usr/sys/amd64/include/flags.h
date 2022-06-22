#ifndef _MACHINE_FLAGS_H_
#define _MACHINE_FLAGS_H_

/*
 * Processor-defined flags that can be accessed through
 * the processor status long (rflags).
 */
#define FL_CARRY	0x0001		/* carry flag */
#define FL_PARITY	0x0008		/* parity flag */
#define FL_ADJUST	0x0010		/* adjust flag */
#define FL_ZERO		0x0040		/* zero flag */
#define FL_SIGN		0x0080		/* sign flag */
#define FL_TRAP		0x0100		/* trap flag */
#define FL_INTENA	0x0200		/* interrupt enabled flag */
#define FL_DIRECTION	0x0400		/* direction flag */
#define FL_OFLOW	0x0800		/* overflow flag */
#define FL_IOPL		0x3000		/* I/O privilege flag */
#define FL_NESTASK	0x4000		/* nested task flag */

#define FL_RESUME	0x00010000	/* result flag */
#define FL_VIRTUAL	0x00020000	/* virtual x86 mode flag */
#define FL_ALIGNCHK	0x00040000	/* alignment check flag */
#define FL_VIRTINT	0x00080000	/* virtual interrupt flag */
#define FL_VIRTINTPEND	0x00100000	/* virtual interrupt pending flag */

#endif /* !_MACHINE_FLAGS_H_ */
