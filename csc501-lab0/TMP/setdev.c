/* setdev.c - setdev 
 * Syscall number 14*/

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	if (trace_state == true)
        {
                sys_trace[currpid][14] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][14]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }

	short	*nxtdev;

	if (isbadpid(pid))
		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	if (trace_state == true)
        {
                int start = sys_trace[currpid][14];
                sys_trace[currpid][14] = (ctr1000 - start);
                /*sys_count[pid][3] = sys_count[pid][3] + 1;
 *  *                 kprintf("Getprio :%d\n", sys_count[pid][3]);*/
        }

	return(OK);
}
