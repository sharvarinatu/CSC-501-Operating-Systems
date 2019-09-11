/* setnok.c - setnok 
 * Syscall number 15*/

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setnok  -  set next-of-kin (notified at death) for a given process
 *------------------------------------------------------------------------
 */
SYSCALL	setnok(int nok, int pid)
{
	if (trace_state == true)
        {
                sys_trace[currpid][15] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][15]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid)) {
		restore(ps);
		return(SYSERR);
	}
	pptr = &proctab[pid];
	pptr->pnxtkin = nok;
	restore(ps);
	if (trace_state == true)
        {
                int start = sys_trace[currpid][15];
                sys_trace[currpid][15] = (ctr1000 - start);
                /*sys_count[pid][3] = sys_count[pid][3] + 1;
 *  *                 kprintf("Getprio :%d\n", sys_count[pid][3]);*/
        }

	return(OK);
}
