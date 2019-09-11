/* scount.c - scount 
 * Syscall number 11*/

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
	if (trace_state == true)
        {
                sys_trace[currpid][11] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][11]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }

extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);

	if (trace_state == true)
        {
                int start = sys_trace[currpid][11];
                sys_trace[currpid][11] = (ctr1000 - start);
                /*sys_count[pid][3] = sys_count[pid][3] + 1;
 *  *                 kprintf("Getprio :%d\n", sys_count[pid][3]);*/
        }
	return(semaph[sem].semcnt);
}
