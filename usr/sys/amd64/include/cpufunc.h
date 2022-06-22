#ifndef _MACHINE_CPUFUNC_H_
#define _MACHINE_CPUFUNC_H_

/*
 * Memory-mapped I/O related routines.
 */
#define readb(addr)	(*(volatile uint8_t *)addr)
#define readw(addr)	(*(volatile uint16_t *)addr)
#define readl(addr)	(*(volatile uint32_t *)addr)
#define readq(addr)	(*(volatile uint64_t *)addr)

#define writeb(addr, value)	(*(volatile uint8_t *)addr = value)
#define writew(addr, value)	(*(volatile uint16_t *)addr = value)
#define writel(addr, value)	(*(volatile uint32_t *)addr = value)
#define writeq(addr, value)	(*(volatile uint64_t *)addr = value)

static inline void outb(uint32_t port, uint8_t data) {
	asm volatile ("outb %0, %w1" : : "a" (data), "Nd" (port));
}

static inline void outw(uint32_t port, uint16_t data) {
	asm volatile ("outw %0, %w1" : : "a" (data), "Nd" (port));
}

static inline void outl(uint32_t port, uint32_t data) {
	asm volatile ("outl %0, %w1" : : "a" (data), "Nd" (port));
}

/*
 * Reads from a model-specific register.
 */
static inline uint64_t rdmsr(uint32_t msr) {
	uint32_t low, high;

	asm volatile ("rdmsr" : "=a" (low), "=d" (high) : "c" (msr));
	return (low | ((uint64_t)high << 32));
}

/*
 * Writes to a model-specific register.
 */
static inline void wrmsr(uint32_t msr, uint64_t data) {
	uint32_t low, high;

	low = data;
	high = data >> 32;
	asm volatile ("wrmsr" : : "a" (low), "d" (high), "c" (msr));
}

#endif /* !_MACHINE_CPUFUNC_H_ */
