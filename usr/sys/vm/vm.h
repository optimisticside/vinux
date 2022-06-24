#ifndef _VM_VM_H_
#define _VM_VM_H_

#include <sys/types.h>
#include <sys/queue.h>

#include <machine/types.h>
#include <vm/types.h>

/*
 * VM Pager routine defenitions.
 */
typedef struct vm_page	in(struct vm_object *, size_t);
typedef int		out(struct vm_object *, size_t);

/*
 * Holds the mapping of an entire address space that includes
 * the page-map as well as the memory regions.
 */
struct vm_space {
	struct pmap		*vms_pmap;	/* arch-specific memory map */
	queue(struct vm_entry)	*vm_entries;	/* vm regions */
};

/*
 * One allocated per region in a virtual memory space with different
 * access permissions and/or associated objects.
 */
struct vm_entry {
	paddr_t			vme_paddr;		/* physical address */
	vaddr_t			vme_base;		/* address in virtual memory */
	size_t			vme_size;		/* size of region */
	uint32_t		vme_flags;		/* additional flags */
	struct vm_object	*vme_object;		/* associated object */
	size_t			vme_objoff;		/* offset inside object */
};

/*
 * One allocated per physical page in memory.
 */
struct vm_page {
	paddr_t			vmp_phys;		/* physical address */
	size_t			vmp_refcnt;		/* number of references */
	struct vm_object	*vmp_object;		/* assocaited object */
	size_t			vmp_objoff;		/* offset inside object */
};

/*
 * Pages in and out.
 */
struct vm_pager {
	vmp_in_t		vmp_in;			/* page in */
	vmp_out_t		vmp_out;		/* page out */
};

#endif /* !_VM_VM_H_ */
