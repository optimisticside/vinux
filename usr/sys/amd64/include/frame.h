#ifndef _MACHINE_FRAME_H_
#define _MACHINE_FRAME_H_

/*
 * A trapframe stores the CPU state upon a trap. It includes
 * things like registers.
 */
struct trapframe {
	register_t	tf_rdi;
	register_t	tf_rsi;
	register_t	tf_rdx;
	register_t	tf_rcx;
	register_t	tf_r8;
	register_t	tf_r9;
	register_t	tf_rax;
	register_t	tf_rbx;
	register_t	tf_rbp;
	register_t	tf_r10;
	register_t	tf_r11;
	register_t	tf_r12;
	register_t	tf_r13;
	register_t	tf_r14;
	register_t	tf_r15;
	uint32_t	tf_trapno;
	uint16_t	tf_fs;
	uint16_t	tf_gs;
	register_t	tf_addr;
	uint32_t	tf_flags;
	uint16_t	tf_es;
	uint16_t	tf_ds;
	
	/* 
	 * Portion below defined in hardware. Do not change
	 * its order.
	 */
	register_t	tf_err;
	register_t	tf_rip;
	register_t	tf_cs;
	register_t	tf_rflags;
	
	register_t	tf_rsp;
	register_t	tf_ss;	
};

#endif /* !_MACHINE_FRAME_H_ */
