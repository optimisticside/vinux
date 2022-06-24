#include <sys/types.h>
#include <sys/proc.h>

/*
 * Remove a process from its sleep queue.
 */
void unsleep(struct proc *p) {
	struct slpque *slpq;

	if (p->p_wchan != NULL) {
		slpq = &slpque[LOOKUP(wchan)];
		QUEUE_REMOVE(slpq->sq_head, p);
		p->p_wchan = NULL;
	}
}

/*
 * Make all processes sleeping on the specified wakeup-channel runnable.
 */
void wakeup(void *wchan) {
	struct slpque *slpq;
	struct proc *p, **q;

	slpq = &slpque[LOOKUP(wchan)];
	QUEUE_FOREACH(slpq->sq_head, p) {
		if (p->p_wchan == wchan) {
			p->p_wchan = NULL;
			unsleep(p);
		}
	}
}
