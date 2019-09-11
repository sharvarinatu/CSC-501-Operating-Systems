/* signaln.c - signaln 
 * Syscall number 18*/

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  signaln -- signal a semaphore n times
 *------------------------------------------------------------------------
 */
SYSCALL signaln(int sem, int count)
{
	if (trace_state == true)
        {
                sys_trace[currpid][18] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][18]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }

	STATWORD ps;    
	struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || semaph[sem].sstate==SFREE || count<=0) {
		restore(ps);
		return(SYSERR);
	}
	sptr = &semaph[sem];
	for (; count > 0  ; count--)
		if ((sptr->semcnt++) < 0)
			ready(getfirst(sptr->sqhead), RESCHNO);
	resched();
	restore(ps);
	if (trace_state == true)
        {
                int start = sys_trace[currpid][18];
                sys_trace[currpid][18] = (ctr1000 - start);
                /*sys_count[pid][3] = sys_count[pid][3] + 1;
 *  *                 kprintf("Getprio :%d\n", sys_count[pid][3]);*/
        }

	return(OK);
}
