/* getpid.c - getpid 
 * Syscall number 3*/

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	if (trace_state == true)
        {
                sys_trace[currpid][3] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][3]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }	
	
	if (trace_state == true)
        {
                int start = sys_trace[currpid][3];
                sys_trace[currpid][3] = (ctr1000 - start);
        }
	
	return(currpid);
}
