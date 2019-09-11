/* recvclr.c - recvclr 
 * Syscall number 8*/

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  recvclr  --  clear messages, returning waiting message (if any)
 *------------------------------------------------------------------------
 */
SYSCALL	recvclr()
{
	if (trace_state == true)
        {
                sys_trace[currpid][8] = ctr1000;
                sys_count[currpid][0] = 1;
                sys_count[currpid][8]++;
                /* kprintf("Getprio :%d\n", sys_count[pid][3]); */
        }

	STATWORD ps;    
	WORD	msg;

	disable(ps);
	if (proctab[currpid].phasmsg) {
		proctab[currpid].phasmsg = 0;
		msg = proctab[currpid].pmsg;
	} else
		msg = OK;
	restore(ps);

	if (trace_state == true)
        {
                int start = sys_trace[currpid][8];
                sys_trace[currpid][8] = (ctr1000 - start);
                /*sys_count[pid][3] = sys_count[pid][3] + 1;
 *  *                 kprintf("Getprio :%d\n", sys_count[pid][3]);*/
        }
	return(msg);
}
