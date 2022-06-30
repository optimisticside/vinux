#include <sys/param.h>
#include <sys/systm.h>
#include <sys/proc.h>

/*
 * Floating-point support routines.
 */
#define	fldcw(cw)		asm volatile ("fldcw %0" : : "m" (cw))
#define	fnclex()		asm volatile ("fnclex")
#define	fninit()		asm volatile ("fninit")
#define	fnstcw(addr)		asm volatile ("fnstcw %0" : "=m" (*(addr)))
#define	fnstsw(addr)		asm volatile ("fnstsw %0" : "=am" (*(addr)))
#define	fxrstor(addr)		asm volatile ("fxrstor %0" : : "m" (*(addr)))
#define	fxsave(addr)		asm volatile ("fxsave %0" : "=m" (*(addr)))
#define	ldmxcsr(csr)		asm volatile ("ldmxcsr %0" : : "m" (csr))
#define	stmxcsr(addr)		asm volatile ("stmxcsr %0" : "=m" (*(addr)))

/*
 * Table of floating-point exceptions and their corresponding signal codes
 * for SIGFPE.
 */
static char fpe_table[128] = {
	
};
