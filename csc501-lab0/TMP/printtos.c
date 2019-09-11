#include <stdio.h>
#include <kernel.h>

//extern esp;
//register long esp asm("mov %esp, esp");
long *esp;
long *ebp;

long printtos()
{
	asm("movl %esp, esp"); 
	asm("movl %ebp, ebp");
	kprintf("\nBefore[0x%08x] = 0x%08x\n",(ebp+2), *(ebp+2));
	kprintf("After[0x%08x]=0x%08x\n",(ebp), *ebp);

	int i = 0;
	for (i=1; i<=4 ;i++)
	{
		// If contents of the stack are zero, there are no variables inserted in the stack
		if (esp+i < ebp)
		{	
			kprintf("\telement[0x%08x] : 0x%08x\n", (esp+i), *(esp+i)); 
		}
	}

	/* printf("EBP address: 0x%08x\n",(ebp));
	printf("Ebp -2 address: 0x%08x= 0x%08x\n",(ebp-2), *(ebp-2));
	printf("Esp address: 0x%08x\n",(esp)); */
	return 0;
}
