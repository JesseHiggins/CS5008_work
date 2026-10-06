# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
				# (1) What are we setting up here?
				# Ans: Setting up the registers.
	pushq %rbp		#
	movq  %rsp, %rbp	#

				# (2) What is going on here
				# Ans: Copying data from register to register and storing with memory address.
	movq $1, %rax		# 
	movq $1, %rdi		#
	leaq .hello.str,%rsi	#


			# (3) What is syscall? We did not talk about this
			# in class.
			# Ans: A syscall is asking the operating system for a privledged service.
			#
	syscall			# Which syscall is being run?
				# Ans: The rax register is being run.

				# (4) What would another option be instead of 
				# using a syscall to achieve this?
				# Ans: There is something else called int or an interrupt that forces the CPU to pause.

	movq	$60, %rax	# (5) We are again setting up another syscall
	movq	$0, %rdi	# What command is it?
				# Ans:	movq %rax is the command I think.
	syscall

	popq %rbp		# (Note we do not really need
			 	# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	13 is the size of the string.
