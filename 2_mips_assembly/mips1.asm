example:
	.data
var1:	.word	23		# declare storage for var1; initial value is 23

	.text
_start:
	lw	$t0, var1	# load contents of RAM location into register $t0:  $t0 = var1
	li	$t1, 13		#  $t1 = 13   ("load immediate")
	sw	$t1, var1	# store contents of register $t1 into RAM:  var1 = $t1
	sll 	$t2, $t1, 3	# shifts the value of t1 to the left and stores it into t2
	and 	$t3, $t1, $t0	# and bit by bit and stores to $t3
	nor 	$t4, $t3, $t0	# 10111 nor 0101 = 0xffffffe8 e8=1110 1000
	
	# beq reg1, reg2, L1	- go to L1 if reg1 equals reg2
	# bne opposite
	beq 	$t1,$t2,ELSE
	li 	$t5,5
	j EXIT
ELSE:
	li $t5,6
	jr $ra
EXIT: 
	slt  	$t6,$t1,$t2 	#set t6 to 1 if t1 is less than t2
	# ^ and slti works with signed operands 
	# sltu and slstiu works with unsigned
	
	#jal and jr like goto and return statements
	jal ELSE
	 