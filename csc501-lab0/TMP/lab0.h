//#ifndef _lab0_h_
//#define _lab0_h_

#include <kernel.h>
#include <stdbool.h>
//#include <proc.h>

//printsyscallsummary part
unsigned long ctr1000;
void syssummary_start();
void syssummary_stop();
void printsyscallsummary();
extern bool trace_state;
extern int sys_trace[NPROC][28];
extern int sys_count[NPROC][28];
//struct systab a[27];

//#endif
