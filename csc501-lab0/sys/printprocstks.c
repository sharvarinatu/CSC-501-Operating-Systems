#include <stdio.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>


struct pentry process;

void printprocstks(int priority)
{
	//printf ("%d",proctab[0].pprio);
	//int len = sizeof(proctab)/sizeof(proctab[0]);

	//struct pentry *process;
	int i;
	long *esp;

	for(i=0; i<NPROC; i++)
	{
		//printf("%d", proctab[i].pprio);
		// Pass by reference
		process = proctab[i];
		if (process.pprio >= priority)
		{
			kprintf("\nProcess [%s]\n", process.pname);
			kprintf("\tpid: %d\n", i);
			kprintf("\tpriority: %d\n", process.pprio);
			kprintf("\tbase: 0x%08x\n", process.pbase);
			kprintf("\tlimit: 0x%08x\n", process.plimit);
			kprintf("\tlen: %d\n", process.pstklen);
			
			if (i == currpid)
			{
				asm("mov %esp, esp");
				kprintf("\tpointer:0x%08x \n", &esp);
			}
			else
			{
				kprintf("\tpointer:0x%08x \n", process.pesp);
			}
		}
	}

	//printf("Currpid: %d", currpid);
}
