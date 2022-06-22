#ifndef _MACHINE_TRAP_H_
#define _MACHINE_TRAP_H_

/*
 * Processor-defined interrupt codes that are provided through the 
 * trap frame.
 */
#define T_PRIVINS	1	/* privilated instruction */
#define T_BREAKPOINT	3	/* breakpoint instruction */
#define T_ARITHTRAP	6	/* arithmatic trap */
#define T_PAGE		12	/* page fault */
#define T_ALIGN		14	/* alignment fault */

#define T_DIVIDE	18	/* division by zero */
#define T_NMI		19	/* non-maskable interrup t*/
#define T_OVERFLOW	20	/* overflow trap */
#define T_BOUND		21	/* bound instruction fault */
#define T_DOUBLE	23	/* double fault */
#define T_FPOPFETCH	24	/* floating-point coprocessor operand fetch fault */
#define T_INVLTSS	25	/* invalid tss */
#define T_SEGNPRES	26	/* segment not present */
#define T_STACK		27	/* stack fault */
#define T_MACHCHK	28	/* machine check */
#define T_XMM		29	/* SIMD floating point exception */
#define T_RESERVED	30	/* reserved */

#endif /* !_MACHINE_TRAP_H_ */
