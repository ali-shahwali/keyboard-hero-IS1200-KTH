  # vectors.S
  # This file written 2015 by Axel Isaksson
  # Modified 2015 by F Lundevall
  # For copyright and licensing, see file COPYING

.macro movi reg, val
	lui \reg, %hi(\val)
	ori \reg, \reg, %lo(\val)
.endm

.macro STUB num
	.align 4
	.section .vector_new_\num,"ax",@progbits
	.global __vector_\num
	__vector_\num:
		movi $k0, _isr_primary_install
		lw $k0, \num * 4($k0)
		jr $k0
.endm

.align 4

.text


# Interrupts are handled here


	# restore saved registers
	lw $25,68($sp)
	lw $24,64($sp)
	lw $15,60($sp)
	lw $14,56($sp)
	lw $13,52($sp)
	lw $12,48($sp)
	lw $11,44($sp)
	lw $10,40($sp)
	lw  $9,36($sp)
	lw  $8,32($sp)
	lw  $7,28($sp)
	lw  $6,24($sp)
	lw  $5,20($sp)
	lw  $4,16($sp)
	lw  $3,12($sp)
	lw  $2, 8($sp)
	lw  $1, 4($sp)
	lw $ra, 0($sp)
	addi $sp,$sp,72

	.set at
	# now the assembler is allowed to use $1 again

	# standard epilogue follows
	eret
	nop


# Exceptions are handled here (trap, syscall, etc)
.section .gen_handler,"ax",@progbits
.set noreorder
.ent _gen_exception
_gen_exception:
	mfc0 $k0, $14, 0
	addi $k0, $k0, 4
	mtc0 $k0, $14, 0
	eret
	nop

.end _gen_exception
