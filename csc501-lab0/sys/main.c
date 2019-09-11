/* user.c - main */

//#include <lab0.h>
#include <conf.h>
#include <kernel.h>
#include <stdio.h>
#include <lab0.h>
//#include <proc.h>

int prX;
void halt();


/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
prch(c)
char c;
{
	int i;
	sleep(5);	
}


int main()
{
	
	kprintf("\nAssembly code function");
	long result = zfunction(0xaabbccdd);
	kprintf("\nreturned number 0x%08x", result);
	
	kprintf("\n\nPrint Seg Address output:\n");
	printsegaddress();
	
	kprintf("\nPrinting the top of stack and contents:\n");
	printtos();

	kprintf("\nProcess details for more than a priority:\n");
	printprocstks(5);

	kprintf("\nSystem call log:\n");
	syscallsummary_start();
	int i =getprio(5);
	i = getprio(5);
	resume(prX = create(prch,2000,20,"proc X",1,'A'));
	sleep(3);
	syscallsummary_stop();
	printsyscallsummary();
	return 0;
}
