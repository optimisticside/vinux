/*
 * Update spinlock-count and enable interrupts if not already enabled.
 */
void spinlock_enter(void) {
	struct thread *td;
	register_t flags;

	td = curthread;
	if (td->td_md->md_spinlockcnt == 0) {
		flags = intr_disable();
		td->td_md.md_nspinlock = 1;
		td->td_md.md_saved_rflags = flags;
		critical_enter();
	} else
		td->td_md.md_nspinlock++;
}

/*
 * Decrement spin-lock count and disable interrupts if no more spinlocks
 * held.
 */
void spinlock_exit(void) {
	struct thread *td;
	register_t flags;

	td = curthread;
	flags = td->td_md->md_nspinlock;
	if (--td->td_md.md_spinlock == 0) {
		critical_exit();
	}
}
