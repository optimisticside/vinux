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
	uint64_t	gd_highoff:48;		/* higher-part of gate offset */
	uint64_t	gd_xx1:32;		/* unused */
};

/*
 * 
 */
struct segment_descriptor {
	uint64_t	sd_lowlim:16;		/* lower-part of limit */
	uint64_t	sd_lowbase:24;		/* lower-part of base address */
	uint64_t	sd_type:5;		/* segment type */
	uint64_t	sd_dpl:2;		/* descriptor priority level */
	uint64_t	sd_present:1;		/* present flag */
	uint64_t	sd_highlim:4;		/* higher-part of limit */
	uint64_t	sd_def32:1;		/* whether the segment is 32 bits by default */
	uint64_t	sd_gran:1;		/* limit granularity */
	uint64_t	sd_highbase:8;		/* higher-part of base address */
};

#endif /* !_MACHINE_SEGMENTS_H_ */
