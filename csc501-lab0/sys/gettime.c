/* gettime.c - gettime 
 * Syscall number 5*/

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <lab0.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */

	if (trace_state == true)
        {
                sys_trace[currpid][5] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][5]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }

	if (trace_state == true)
        {
                int start = sys_trace[currpid][5];
                sys_trace[currpid][5] = (ctr1000 - start);
                /*sys_count[pid][3] = sys_count[pid][3] + 1;
 *  *                 kprintf("Getprio :%d\n", sys_count[pid][3]);*/
        }

    return OK;
}
