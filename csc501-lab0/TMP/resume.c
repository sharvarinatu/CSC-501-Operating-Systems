/* resume.c - resume */
// syscall number 10  

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * resume  --  unsuspend a process, making it ready; return the priority
 *------------------------------------------------------------------------
 */
SYSCALL resume(int pid)
{
	if (trace_state == true)
        {
                //kprintf("Pid in Resume: %d", currpid);
		sys_trace[currpid][10] = ctr1000;
                //kprintf("Resume PID: %d", getpid());
		sys_count[currpid][0] = 1;
                sys_count[currpid][10]++;
        }

	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority to return		*/

	disable(ps);
	if (isbadpid(pid) || (pptr= &proctab[pid])->pstate!=PRSUSP) {
		restore(ps);
		return(SYSERR);
	}
	prio = pptr->pprio;
	ready(pid, RESCHYES);
	restore(ps);
	
	if (trace_state == true)
        {
                int start = sys_trace[currpid][10];
                sys_trace[currpid][10] = (ctr1000 - start);
        }

	return(prio);
}
