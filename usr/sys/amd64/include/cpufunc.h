#ifndef _MACHINE_CPUFUNC_H_
#define _MACHINE_CPUFUNC_H_

#include <machine/types.h>

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

/*
 * Reads information about the processor through the cpuid instruction.
 */
static inline void cpuid(uint32_t leaf, uint32_t subleaf,
		uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx) {
	asm volatile ("cpuid"
		: "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
		: "0" (leaf), "c" (subleaf);
}

/*
 * Enables interrupts.
 */
static inline void enable_irq() {
	asm volatile ("sti");
}

/*
 * Disables interrupts.
 */
static inline void disable_irq() {
	asm volatile ("cli");
}

/*
 * Port I/O routines.
 */

static inline uint8_t inb(uint32_t port) {
	uint8_t data;

	asm volatile ("inb %w1, %0" : "=a" (data) : "Nd" (port));
	return data;
}

static inline uint16_t inw(uint32_t port) {
	uint16_t data;

	asm volatile ("inw %w1, %0" : "=a" (data) : "Nd" (port));
	return data;
}

static inline uint32_t inl(uint32_t port) {
	uint32_t data;

	asm volatile ("inl %w1, %0" : "=a" (data) : "Nd" (port));
	return data;
}


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

/*
 * Reads from the timestamp counter.
 */
static inline uint64_t rdtsc() {
	uint32_t low, high;

	asm volatile ("rdtsc" : "=a" (low), "=d" (high));
	return (low | ((uint64_t)high << 32));
}

static inline uint64_t read_cr0() {
	uint64_t value;

	asm volatile ("movq %%cr0, %0" : "=r" (value));
	return value;
}

static inline uint64_t read_cr1() {
	uint64_t value;

	asm volatile ("movq %%cr1, %0" : "=r" (value));
	return value;
}

static inline uint64_t read_cr2() {
	uint64_t value;

	asm volatile ("movq %%cr2, %0" : "=r" (value));
	return value;
}

static inline uint64_t read_cr3() {
	uint64_t value;

	asm volatile ("movq %%cr3, %0" : "=r" (value));
	return value;
}

static inline uint64_t read_cr4() {
	uint64_t value;

	asm volatile ("movq %%cr4, %0" : "=r" (value));
	return value;
}

static inline uint64_t write_cr0(uint64_t value) {
	asm volatile ("movq %0, %%cr0" : : "r" (value));
}

static inline uint64_t write_cr1(uint64_t value) {
	asm volatile ("movq %0, %%cr1" : : "r" (value));
}


static inline uint64_t write_cr2(uint64_t value) {
	asm volatile ("movq %0, %%cr2" : : "r" (value));
}

static inline uint64_t write_cr3(uint64_t value) {
	asm volatile ("movq %0, %%cr3" : : "r" (value));
}

static inline uint64_t write_cr4(uint64_t value) {
	asm volatile ("movq %0, %%cr4" : : "r" (value));
}

/*
 * Global TLB flush.
 */
static inline void invltlb() {
	write_cr3(read_cr3());
}

/*
 * TLB flush for an individual page.
 */
static inline void invlpg(uint64_t addr) {
	asm volatile ("invlpg %0" : : "m" (*(char *)addr));
}

#endif /* !_MACHINE_CPUFUNC_H_ */
