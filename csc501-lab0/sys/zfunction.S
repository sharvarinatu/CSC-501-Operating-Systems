	.globl zfunction

zfunction:
	push %ebp
    	mov %esp, %ebp
    	
	mov 8(%ebp), %eax
	and $0xfffc01ff, %eax
	shr $0x8, %eax
	or $0xff000000, %eax	

    	pop %ebp
        ret
