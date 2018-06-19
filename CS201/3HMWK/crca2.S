/* 
Raul Zarate
CS 201 hmwk3
In this code the it has optimazation to the code created in crca1.  it reads the main crc file and uses this code instead of crc.c
*/


.global crcTable
.global crcFast
.global crcInit

.text
crcInit:
	mov $0 , %rbx			# remainder
	mov $0 , %rdx 			 # dividend

loop1:
	mov $8 , %rcx 			#bit

	movq %rdx , %rbx #remainder = dividend;
      #crcTable[dividend] = remainder;

	cmp $255 , %rdx 
	jle loop2

	jmp end
	
loop2:	
	mov %rbx , %rsi #pass remainder to knew register
	cmp $0 , %rcx #bit
	jle megablaster

	mov %rbx , %rax
	sal $1 , %rax
	mov %rax , %r8
	xorq $0xD5, %rax
	and $0x80 , %rsi
	cmp $0 , %rsi
	cmovle %r8 , %rax
	mov %rax , %rbx

		decq %rcx
		jmp loop2
		
megablaster:
	mov $crcTable , %rdi
	mov %rbx , (%rdi , %rdx , 1)  
	incq %rdx
	
	jmp loop1
	
end: #ends program
ret

crcFast:
	#rdi is message
	#rsi is nBytes
	mov $0 , %rdx #data
	mov $0 , %rax #remainder
	mov $0 , %rcx #byte
	
	floops:
	cmp %rcx , %rsi 
	jle done
			
	#data:
	movb  (%rdi , %rcx , 1) , %dl #data
	xorq %rdx , %rax  # ^

	#remainder:
	mov $crcTable , %r11
	movb  (%r11 , %rdx , 1) , %al  #remainder
	inc %rcx
	jmp floops
	
#exit if greater than nBytes
done:
ret
	
	#lecture 9 slide 16
	

.data 
testtext:
	.asciz "test"
.data
crcTable:
	.rept 256 
	.byte 0
	.endr


