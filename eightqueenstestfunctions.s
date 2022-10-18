


addi a0, x0, 4
addi a1, x0, 1
jal ra, difference

addi a7, x0, 1
ecall

exit:   addi    a7, x0, 10      
        ecall

difference:
	addi 	sp, sp, -4 	# allocate space for word
	sw 	ra, 0(sp)	# preserve ra on stack
	bge 	a1, a0, d_else	# if i >= j, go to else
	sub 	a0, a0, a1	# j - i
	beq	x0, x0, d_exit	# go to exit
d_else:	sub	a0, a1, a0	# i - j
d_exit:	
	lw	ra, 0(sp)	# load ra from stack
	addi	sp, sp, 4	# deallocate space from stack
	jr 	ra		# return from function
	
	
