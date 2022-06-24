#include <sys/types.h>
#include <sys/proc.h>
#include <sys/lock.h>

/*
 * There are two different types of sleep queues. One is the chain of sleep
 * queues that are all attached to the same waiting channel, and the other is
 * a list of free sleep queues.
 */
struct sleepqueue {
	QUEUE_ENTRY(struct sleepqueue) sq_chain; /* entry in sleep queue chain */
	QUEUE_ENTRY(struct sleepqueue) sq_free;	/* entry in queue of free sleep-queues */
	void		*sq_wchan;		/* waiting channel */
};

static struct sleepqueue_chain {
	QUEUE_HEAD(struct sleepqueue) sq_head;	/* queue of sleepqueues */
	struct mtx	sc_mtx;			/* spin lock */
} sleepq_chains[SLPQC_TBLSIZ];

/*
 * Locks the sleepqueue-chain associated with the given waiting channel.
 */
void sleepq_lock(void *wchan) {
	struct sleepqueue_chain *sc;

	sc = sleepq_chains[LOOKUP(wchan)];
	mtx_spin_lock(&sc->sc_lock);
}

/*
 * Unlocks the sleepqueue-chain associated with the given waiting channel.
 */
void sleepq_unlock(void *wchan) {
	struct sleepqueue_chain *sc;

	sc = sleepq_chains[LOOKUP(wchan)];
	mtx_spin_unlock(&sc->sc_lock);
}

/*
 * Looks up a sleep queue with the given waiting channel in the
 * sleepqueue-chain associated with the waiting channel.
 */
struct sleepqueue *sleepq_lookup(void *wchan) {
	struct sleepqueue_chain *sc;
	struct sleepqueue *sq;

	sc = sleepq_chains[LOOKUP(wchan)];
	QUEUE_FOREACH(sq, sc->sc_head) {
		if (sq->sq_wchan == wchan)
			return sq;
	}
	return NULL;
}

/*
 * Adds the current thread onto the sleep queue for the given waiting channel.
 */
void sleepq_add(void *wchan, struct lock_object *lock, int flags) {
	struct sleepqueue_chain *sc;
	struct sleepqueue *sq;
	struct thread *td;

	td = curthread;
	sc = sleepq_chains[LOOKUP(wchan)];
	mtx_assert_owned(&sc->sc_lock);

	if ((sq = sleepq_lookup(wchan)) == NULL) {
		sq = td->td_sleepq;
		sq->sq_wchan = wchan;
	}
}

/*
 * Switches to another thread if the current thread is still asleep in a queue.
 * Returns with thread lock acquired.
 */
void sleepq_switch(void *wchan, int priority) {
	struct sleepqueue_chain *sc;
	struct sleepqueue *sq;
	struct thread *td;

	td = curthread;
	sc = sleepq_chains[LOOKUP(wchan)];
	mtx_assert_owned(&sc->sc_lock);
	/* TODO: Finish this (call sched_switch to actually switch) */
}
