  # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #
.globl time2string
.globl delay
.globl enable_interrupt

.text
# LAB 3 ASSIGNMENT 3
enable_interrupt:
	PUSH $ra
	ei
	POP $ra
	jr $ra
	nop

# Egen kod
time2string:
	PUSH $s0 #store away $s0
	PUSH $ra #store away $ra
	
	move $s0, $a0 #copy ageument to reg($s0)
	
	andi $t0, $a1, 0xf000 #mask first 4 bits (minutes)
	srl $a0, $t0, 12 #shift to lsb
	jal hexasc #jump to hexasc with argument
	nop
	move $t1, $v0 #copy return value to $t1
	sb $t1, 0($s0) #copy $t1 to bit-index 0 in $s0
	
	andi $t0, $a1, 0x0f00 
	srl $a0, $t0, 8
	jal hexasc
	nop
	move $t1, $v0
	sb $t1, 1($s0)
	
	li $t2, 0x3A # store 0x3A (ACII for :) in $t2
	sb $t2, 2($s0) # store : in bit-index 2 in $s0
	
	andi $t0, $a1, 0x00f0 
	srl $a0, $t0, 4
	jal hexasc
	nop
	move $t1, $v0
	sb $t1, 3($s0)
	
	andi $t0, $a1, 0x000f 
	move $a0,$t0
	jal hexasc
	nop
	move $t1, $v0
	sb $t1, 4($s0)
	
	li $t2, 0x00
	sb $t2, 5($s0)
	
	POP $ra
	POP $s0
	jr $ra
	nop
	
delay: #delay by looping in and out
	jr $ra
	nop
hexasc: #convert input hex to string
	andi $t0, $a0, 0xf
	
	ble $t0, 9, siffror
	nop
	
	ble $t0, 15, bokstav
	nop
	
siffror: #if input is 0-9
	addi $v0, $t0, 0x30
	jr $ra
	nop
bokstav: #if input is 10-15
	addi $v0, $t0, 0x37
	jr $ra
	nop
