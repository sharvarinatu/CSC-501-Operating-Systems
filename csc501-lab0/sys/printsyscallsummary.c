#include <stdio.h>
#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdbool.h>
#include <lab0.h>
//#include <string.h>

/*struct sys_trace {
	unsigned long start;  //syscall started
	unsigned long end;    //syscall ends

};*/

int sys_trace[NPROC][28];
int sys_count[NPROC][28];
bool trace_state;
//unsigned long ctr1000;
char sys_call_map[28][14] = {"", "sys_freemem","sys_chprio", "sys_getpid", "sys_getprio", "sys_gettime", "sys_kill", "sys_receive", "sys_recvclr", "sys_recvtime", "sys_resume", "sys_scount", "sys_sdelete", "sys_send","sys_setdev","sys_setnok","sys_screate", "sys_signal", "sys_signaln", "sys_sleep", "sys_sleep10", "sys_sleep100", "sys_sleep1000", "sys_sreset", "sys_stacktrace", "sys_suspend", "sys_unsleep","sys_wait" };

void printsyscallsummary()
{
	//Loop through the processes
	int i = 0, j=0;
	for (i=0; i< NPROC; i++)
	{
		//kprintf("Pid0: %d", sys_count[0][0]);
		if (sys_count[i][0] == 1){
		kprintf("Process [pid:%d]\n", i);
		
		for (j =0; j <28; j++){
			
			if (sys_trace[i][j] != 0)
			{
				//kprintf("Process [pid:%d]\n", i);
				kprintf ("\tSyscall: %s, count: %d, Average execution time: %d (ms)\n", sys_call_map[j], sys_count[i][j], sys_trace[i][j]/sys_count[i][j]);
			}
		}
		}
	}
}

void syscallsummary_start()
{
//	memset(sys_trace, 0, sizeof(sys_trace[0][0]) * 27 * NPROC);
	int i = 0, j = 0;
	for (i = 0; i<NPROC; i++){
		for (j = 0; j<28; j++){
			sys_trace[i][j] = 0;
		}
	} 
	
	for (i = 0; i<NPROC; i++){
                for (j = 0; j<28; j++){
                        sys_count[i][j] = 0;
                }
        }
	trace_state = true;
}

void syscallsummary_stop()
{
	trace_state = false;
}

//extern struct sys_trace systab[];
