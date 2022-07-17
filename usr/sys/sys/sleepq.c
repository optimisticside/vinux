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
} sleepq_chains[NSLEEPQCHAIN];

/*
 * Initializes all sleep-queues.
 */
void sleepq_init() {
	struct sleepqueue_chain *sc;

	for (sc = &sleepq_chains[0]; sc < &sleepq_chains[NSLEEPQCHAIN], sc++) {
		/* TODO: Do this */
	}
}

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
 * Removes all processes from a sleep-queue that match a process-validation
 * routine.
 */
int sleepq_remove(struct sleepqueue *sq, int queue,
		int (*match)(struct proc *)) {

}

/*
 * Broadcasts a sleep-signal to all threads sleeping on a specific waiting
 * channel.
 */
int sleepq_broadcast(void *wchan, int queue) {
	struct sleepqueue *sq;

	KASSERT(wchan != NULL, ("%s: invalid NULL waiting channel", __func__));
	if ((sq = sleepq_lookup(wchan)) == NULL)
		return 0;
	return sleepq_remove(sq, queue, match_any, );
}

/*
 * Switche to another thread if the current thread is still asleep in a queue.
 * Return with thread lock acquired.
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
