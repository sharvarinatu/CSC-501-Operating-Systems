/* sleep.c - sleep */
// syscall number 19
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{
	if (trace_state == true)
        {
                sys_trace[currpid][19] = ctr1000;
		sys_count[currpid][0] = 1;
                sys_count[currpid][19]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }

	STATWORD ps;    
	if (n<0 || clkruns==0)
		return(SYSERR);
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);

	if (trace_state == true)
        {
                int start = sys_trace[currpid][19];
                sys_trace[currpid][19] = (ctr1000 - start);
                /*sys_count[pid][3] = sys_count[pid][3] + 1;
 *                 kprintf("Getprio :%d\n", sys_count[pid][3]);*/
        }
	return(OK);
}
