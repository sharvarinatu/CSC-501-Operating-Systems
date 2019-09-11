/* getprio.c - getprio */
// syscall number 4
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
//#include "printsyscallsummary.c"
#include <stdbool.h>
#include <lab0.h>
//#include "clkinit.c"

/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */

//unsigned long ctr1000;

SYSCALL getprio(int pid)
{
	if (trace_state == true)
	{
		sys_trace[currpid][4] = ctr1000;
		sys_count[currpid][0] = 1;
		sys_count[currpid][4]++;
       	}
	
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		return(SYSERR);
	}
	restore(ps);
	if (trace_state == true)
	{
		int start = sys_trace[currpid][4];
		sys_trace[currpid][4] = (ctr1000 - start);
		/*sys_count[pid][3] = sys_count[pid][3] + 1;
		kprintf("Getprio :%d\n", sys_count[pid][3]);*/
	}
	return(pptr->pprio);
}
