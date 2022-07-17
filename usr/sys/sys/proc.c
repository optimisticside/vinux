#include <sys/types.h>
#include <sys/assert.h>
#include <sys/proc.h>

/*
 * Change current thread state to runnable, placing it in run-queue if it is
 * in memory.
 *
 * Requries the thread lock on entry, drops upon exit.
 */
int setrunnable(struct thread *td) {
	ASSERT(td->td_proc->p_state == PRS_ZOMBIE,
		("setrunnable: %d is a zombie", td->td_proc->p_pid));

	switch (td->td_state) {
	case TDS_RUNNING:
	case TDS_ENQUEUED:
			break;
	case TDS_READY:
			sched_wakeup(td);
			return 0;
	default:
		panic("setrunnable: invalid state %d", td->td_state);
	}
}

/*
 * Make all threads sleeping on the specified wakeup-channel runnable.
 */
void wakeup(void *wchan) {
	sleepq_lock(wchan);
	sleepq_broadcast(wchan, SLEEPQ_SLEEP);
	sleepq_unlock(wchan);
}

/*
 * Suspend current thread until wakeup occurs on specified identifier. Once
 * awakened, the thread will be scheduled to run with the specified priority.
 */
int sleep(void *wchan, struct lock_object *lock, int priority, int flags) {
	struct thread *td;

	td = curthread;
	sleepq_lock(wchan);
	if (flags & )
}
