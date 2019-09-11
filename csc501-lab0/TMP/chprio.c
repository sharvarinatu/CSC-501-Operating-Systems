/* chprio.c - chprio 
 * Syscall number 2*/

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{
	if (trace_state == true)
        {
                sys_trace[currpid][2] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][2]++;
        }

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);

	if (trace_state == true)
        {
                int start = sys_trace[currpid][2];
                sys_trace[currpid][2] = (ctr1000 - start);
        }
	
	return(newprio);
}
