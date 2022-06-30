#ifndef _SYS_SYSTM_H_
#define _SYS_SYSTM_H_

static inline void critical_enter(void) {
	struct thread *td;

	td = curthread;
	td->td_critnest++;

}

#endif /* !_SYS_SYSTM_H_ */
