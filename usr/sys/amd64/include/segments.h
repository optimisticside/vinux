#ifndef _MACHINE_SEGMENTS_H_
#define _MACHINE_SEGMENTS_H_

/*
 * Gate descriptors are used for things like interrupts and traps
 * and indirect descriptors.
 */
struct gate_descriptor {
	uint64_t	gd_lowoff:16;		/* lower-part of gate offset */
	uint64_t	gd_selector:16;		/* segemnt selector */
	uint64_t	gd_istidx:3;		/* index in IST */
	uint64_t	gd_xx:5;		/* unused */
	uint64_t	gd_type:5;		/* segment type */
	uint64_t	gd_dpl:2;		/* descriptor priority level */
	uint64_t	gd_present:1;		/* present flag */
	uing64_t	gd_highoff:48;		/* higher-part of gate offset */
	uint64_t	gd_xx1:32;		/* unused */
};

#endif /* !_MACHINE_SEGMENTS_H_ */
