#ifndef _MACHINE_TSS_H_
#define _MACHINE_TSS_H_

#include <sys/attributes.h>

#include <machine/types.h>

/*
 * TSS (Task State Segment) data type.
 *
 * Only applies to the TSS in long mode (stores the interrupt stack table
 * instead of task execution state).
 */
struct cpu_tss {
	uint32_t	tss_xx;		/* reserved */
	uint64_t	tss_rsp0;	/* ring 0 kernel stack pointer */
	uint64_t	tss_rsp1;	/* ring 1 kernel stack pointer */
	uint64_t	tss_rsp2;	/* ring 2 kernel stack pointer */
	uint64_t	tss_xx1;	/* reserved */
	uint64_t	tss_ist1;	/* interrupt stack table 1 */
	uint64_t	tss_ist2;	/* interrupt stack table 2 */
	uint64_t	tss_ist3;	/* interrupt stack table 3 */
	uint64_t	tss_ist4;	/* interrupt stack table 4 */
	uint64_t	tss_ist5;	/* interrupt stack table 5 */
	uint64_t	tss_ist6;	/* interrupt stack table 6 */
	uint16_t	tss_iobase;	/* I/O bitmap offset */
} __packed;

#endif /* !_MACHINE_TSS_H_ */
