.data

hello:
	.ascii "hello, olvasonaplo!\n"
.text
	.global _start

_start:
	movl $4, %eax
	movl $1, %ebx
	movl $hello, %ecx
	movl $22, %edx
	
	int $0x80
	
	movl $1, %eax
	movl $0, %ebx

	int $0x80
