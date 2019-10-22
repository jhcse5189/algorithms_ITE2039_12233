	.file	"2-1.cpp"
	.text
	.align 2
	.p2align 4,,15
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.19, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.19:
.LFB2270:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	movq	%rsi, %r12
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdx, %rbx
	movq	%rdi, %rbp
	subq	%rsi, %rbx
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	cmpq	$15, %rbx
	movq	%rbx, (%rsp)
	ja	.L12
	movq	(%rdi), %rdx
	cmpq	$1, %rbx
	movq	%rdx, %rax
	jne	.L4
	movzbl	(%rsi), %eax
	movb	%al, (%rdx)
	movq	(%rdi), %rdx
.L5:
	movq	(%rsp), %rax
	movq	%rax, 8(%rbp)
	movb	$0, (%rdx,%rax)
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L13
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L12:
	.cfi_restore_state
	xorl	%edx, %edx
	movq	%rsp, %rsi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm@PLT
	movq	(%rsp), %rdx
	movq	%rax, 0(%rbp)
	movq	%rdx, 16(%rbp)
.L3:
	movq	%rbx, %rdx
	movq	%r12, %rsi
	movq	%rax, %rdi
	call	memcpy@PLT
	movq	0(%rbp), %rdx
	jmp	.L5
.L4:
	testq	%rbx, %rbx
	je	.L5
	jmp	.L3
.L13:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE2270:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.19, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.19
	.p2align 4,,15
	.globl	_Z11median_of_3Piii
	.type	_Z11median_of_3Piii, @function
_Z11median_of_3Piii:
.LFB1686:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movl	%esi, %r13d
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movl	%edx, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	subl	%r13d, %ebp
	movq	%rdi, %r14
	addl	$1, %ebp
	call	rand@PLT
	cltd
	idivl	%ebp
	leal	(%rdx,%r13), %r12d
	.p2align 4,,10
	.p2align 3
.L15:
	call	rand@PLT
	cltd
	idivl	%ebp
	leal	(%rdx,%r13), %ebx
	cmpl	%ebx, %r12d
	je	.L15
	.p2align 4,,10
	.p2align 3
.L26:
	call	rand@PLT
	cltd
	idivl	%ebp
	leal	(%rdx,%r13), %eax
	cmpl	%eax, %ebx
	je	.L26
	cmpl	%eax, %r12d
	je	.L26
	movslq	%r12d, %r12
	movslq	%ebx, %rdx
	movslq	%eax, %rcx
	movl	(%r14,%rdx,4), %edx
	cmpl	%edx, (%r14,%r12,4)
	movl	(%r14,%rcx,4), %ecx
	jge	.L17
	cmpl	%ecx, %edx
	cmovl	%ebx, %eax
.L14:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L17:
	.cfi_restore_state
	jle	.L14
	cmpl	%ecx, %edx
	cmovg	%ebx, %eax
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1686:
	.size	_Z11median_of_3Piii, .-_Z11median_of_3Piii
	.p2align 4,,15
	.globl	_Z9partitionPiii
	.type	_Z9partitionPiii, @function
_Z9partitionPiii:
.LFB1685:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movslq	%edx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbp
	movl	%r13d, %edx
	movl	%esi, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	call	_Z11median_of_3Piii
	leaq	0(%rbp,%r13,4), %r10
	cltq
	cmpl	%r13d, %ebx
	leaq	0(%rbp,%rax,4), %rax
	movl	(%r10), %edx
	movl	(%rax), %r8d
	movl	%edx, (%rax)
	movslq	%ebx, %rdx
	movl	%r8d, (%r10)
	leaq	0(%rbp,%rdx,4), %rsi
	jge	.L32
	movq	%r13, %r12
	leal	-1(%rbx), %r9d
	movl	(%rsi), %r11d
	subl	$1, %r12d
	movq	%rsi, %rcx
	subl	%ebx, %r12d
	addq	%rdx, %r12
	leaq	4(%rbp,%r12,4), %rbx
	jmp	.L35
	.p2align 4,,10
	.p2align 3
.L37:
	movl	(%r10), %r8d
.L35:
	movl	(%rcx), %edi
	leal	1(%r9), %eax
	movslq	%eax, %rdx
	salq	$2, %rdx
	cmpl	%r8d, %edi
	leaq	0(%rbp,%rdx), %rsi
	jg	.L33
	movl	%edi, (%rsi)
	leaq	4(%rbp,%rdx), %rsi
	leal	2(%r9), %edi
	movl	%r11d, (%rcx)
	movl	%eax, %r9d
	movl	(%rsi), %r11d
	movl	%edi, %eax
.L33:
	addq	$4, %rcx
	cmpq	%rbx, %rcx
	jne	.L37
.L34:
	leaq	0(%rbp,%r13,4), %rdx
	movl	(%rdx), %ecx
	movl	%ecx, (%rsi)
	movl	%r11d, (%rdx)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L32:
	.cfi_restore_state
	movl	(%rsi), %r11d
	movl	%ebx, %eax
	movq	%rdx, %r13
	jmp	.L34
	.cfi_endproc
.LFE1685:
	.size	_Z9partitionPiii, .-_Z9partitionPiii
	.p2align 4,,15
	.globl	_Z14insertion_sortPiii
	.type	_Z14insertion_sortPiii, @function
_Z14insertion_sortPiii:
.LFB1687:
	.cfi_startproc
	leal	1(%rsi), %r11d
	cmpl	%edx, %r11d
	jge	.L49
	movslq	%r11d, %rax
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	%esi, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	leaq	-4(%rdi,%rax,4), %rax
	notl	%ebp
	.p2align 4,,10
	.p2align 3
.L41:
	cmpl	%r11d, %esi
	jge	.L52
	movl	4(%rax), %ecx
	cmpl	%ecx, (%rax)
	jle	.L52
	leal	0(%rbp,%r11), %r8d
	leaq	4(%rax), %rbx
	movq	%rax, %r10
	salq	$2, %r8
	movq	%rbx, %rdi
	subq	%r8, %r10
	jmp	.L43
	.p2align 4,,10
	.p2align 3
.L47:
	movl	(%rax), %ecx
	subq	$4, %rdi
	subq	$4, %rax
	cmpl	%ecx, -4(%r9)
	jle	.L42
.L43:
	movl	(%rax), %r8d
	cmpq	%r10, %rax
	movl	%ecx, (%rax)
	movq	%rax, %r9
	movl	%r8d, (%rdi)
	jne	.L47
.L42:
	addl	$1, %r11d
	movq	%rbx, %rax
	cmpl	%r11d, %edx
	jne	.L41
.L53:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L52:
	.cfi_restore_state
	leaq	4(%rax), %rbx
	addl	$1, %r11d
	cmpl	%r11d, %edx
	movq	%rbx, %rax
	jne	.L41
	jmp	.L53
.L49:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	.cfi_restore 6
	rep ret
	.cfi_endproc
.LFE1687:
	.size	_Z14insertion_sortPiii, .-_Z14insertion_sortPiii
	.p2align 4,,15
	.globl	_Z17hybrid_quick_sortPiii
	.type	_Z17hybrid_quick_sortPiii, @function
_Z17hybrid_quick_sortPiii:
.LFB1684:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	%edx, %eax
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subl	%esi, %eax
	movq	%rdi, %r13
	movl	%esi, %ebx
	movl	%edx, %ebp
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	cmpl	$9, %eax
	jle	.L55
.L60:
	cmpl	%ebp, %ebx
	jge	.L54
	movl	%ebx, %esi
	movl	%ebp, %edx
	movq	%r13, %rdi
	call	_Z9partitionPiii
	movl	%eax, %r12d
	leal	-1(%rax), %edx
	movl	%ebx, %esi
	movq	%r13, %rdi
	leal	1(%r12), %ebx
	call	_Z17hybrid_quick_sortPiii
	movl	%ebp, %eax
	subl	%ebx, %eax
	cmpl	$9, %eax
	jg	.L60
.L55:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movl	%ebp, %edx
	movl	%ebx, %esi
	movq	%r13, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	jmp	_Z14insertion_sortPiii
	.p2align 4,,10
	.p2align 3
.L54:
	.cfi_restore_state
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1684:
	.size	_Z17hybrid_quick_sortPiii, .-_Z17hybrid_quick_sortPiii
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"input_100000.txt"
.LC1:
	.string	"output2-1.txt"
.LC2:
	.string	" "
.LC3:
	.string	"\n"
.LC5:
	.string	" s"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1683:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1683
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	xorl	%edi, %edi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$1160, %rsp
	.cfi_def_cfa_offset 1216
	movq	%fs:40, %rax
	movq	%rax, 1144(%rsp)
	xorl	%eax, %eax
	call	time@PLT
	movl	%eax, %edi
	leaq	48(%rsp), %r15
	call	srand@PLT
	movl	$800000, %edi
.LEHB0:
	call	_Znam@PLT
	leaq	16+.LC0(%rip), %rdx
	movq	%rax, %r13
	leaq	16(%r15), %rax
	movq	%r15, %rdi
	leaq	-16(%rdx), %rsi
	movq	%rax, 48(%rsp)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.19
.LEHE0:
	leaq	80(%rsp), %rdi
	leaq	13+.LC1(%rip), %rdx
	leaq	16(%rdi), %rax
	leaq	-13(%rdx), %rsi
	movq	%rdi, 8(%rsp)
	movq	%rax, 80(%rsp)
.LEHB1:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructIPKcEEvT_S8_St20forward_iterator_tag.isra.19
.LEHE1:
	leaq	624(%rsp), %r14
	movl	$8, %edx
	movq	%r15, %rsi
	movq	%r14, %rdi
.LEHB2:
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1ERKNSt7__cxx1112basic_stringIcS1_SaIcEEESt13_Ios_Openmode@PLT
.LEHE2:
	xorl	%ebx, %ebx
	leaq	44(%rsp), %r12
	jmp	.L64
	.p2align 4,,10
	.p2align 3
.L89:
	movl	44(%rsp), %eax
	movl	%eax, 0(%r13,%rbx,4)
	addq	$1, %rbx
.L64:
	movq	%r12, %rsi
	movq	%r14, %rdi
.LEHB3:
	call	_ZNSirsERi@PLT
	movq	(%rax), %rdx
	movq	-24(%rdx), %rdx
	testb	$5, 32(%rax,%rdx)
	je	.L89
	leaq	_ZSt4cout(%rip), %rdi
	movl	%ebx, %esi
	call	_ZNSolsEi@PLT
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@PLT
	call	clock@PLT
	leal	-1(%rbx), %edx
	xorl	%esi, %esi
	movq	%r13, %rdi
	leaq	112(%rsp), %r12
	movq	%rax, 16(%rsp)
	call	_Z17hybrid_quick_sortPiii
	call	clock@PLT
	leaq	.LC1(%rip), %rsi
	movl	$48, %edx
	movq	%r12, %rdi
	movq	%rax, 24(%rsp)
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode@PLT
.LEHE3:
	leaq	112(%r12), %rdi
	call	_ZNKSt12__basic_fileIcE7is_openEv@PLT
	testb	%al, %al
	je	.L70
	testl	%ebx, %ebx
	je	.L68
	leal	-1(%rbx), %eax
	movq	%r13, %rbp
	leaq	4(%r13,%rax,4), %rbx
	.p2align 4,,10
	.p2align 3
.L69:
	movl	0(%rbp), %esi
	movq	%r12, %rdi
.LEHB4:
	call	_ZNSolsEi@PLT
	leaq	.LC2(%rip), %rsi
	movl	$1, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	addq	$4, %rbp
	cmpq	%rbp, %rbx
	jne	.L69
.L68:
	leaq	.LC3(%rip), %rsi
	movl	$1, %edx
	movq	%r12, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	112(%rsp), %rax
	pxor	%xmm0, %xmm0
	movq	%r12, %rdi
	movq	-24(%rax), %rdx
	addq	%r12, %rdx
	movl	24(%rdx), %eax
	andl	$-261, %eax
	orl	$4, %eax
	movl	%eax, 24(%rdx)
	movq	24(%rsp), %rax
	subq	16(%rsp), %rax
	cvtsi2ssq	%rax, %xmm0
	divss	.LC4(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	.LC5(%rip), %rsi
	movl	$2, %edx
	movq	%rax, %rdi
	movq	%rax, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	.LC3(%rip), %rsi
	movq	%rbx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
.LEHE4:
.L70:
	movq	%r13, %rdi
	call	_ZdaPv@PLT
	movq	%r12, %rdi
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	%r14, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@PLT
	movq	8(%rsp), %rax
	movq	80(%rsp), %rdi
	addq	$16, %rax
	cmpq	%rax, %rdi
	je	.L67
	call	_ZdlPv@PLT
.L67:
	movq	48(%rsp), %rdi
	addq	$16, %r15
	cmpq	%r15, %rdi
	je	.L71
	call	_ZdlPv@PLT
.L71:
	xorl	%eax, %eax
	movq	1144(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L90
	addq	$1160, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L90:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
.L82:
	movq	%r12, %rdi
	movq	%rax, %rbx
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT
.L73:
	movq	%r14, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev@PLT
.L74:
	movq	8(%rsp), %rdx
	movq	80(%rsp), %rdi
	addq	$16, %rdx
	cmpq	%rdx, %rdi
	je	.L76
	call	_ZdlPv@PLT
.L76:
	movq	48(%rsp), %rdi
	addq	$16, %r15
	cmpq	%r15, %rdi
	je	.L77
	call	_ZdlPv@PLT
.L77:
	movq	%rbx, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
.L81:
	movq	%rax, %rbx
	jmp	.L73
.L80:
	movq	%rax, %rbx
	jmp	.L74
.L79:
	movq	%rax, %rbx
	jmp	.L76
	.cfi_endproc
.LFE1683:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1683:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1683-.LLSDACSB1683
.LLSDACSB1683:
	.uleb128 .LEHB0-.LFB1683
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1683
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L79-.LFB1683
	.uleb128 0
	.uleb128 .LEHB2-.LFB1683
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L80-.LFB1683
	.uleb128 0
	.uleb128 .LEHB3-.LFB1683
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L81-.LFB1683
	.uleb128 0
	.uleb128 .LEHB4-.LFB1683
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L82-.LFB1683
	.uleb128 0
	.uleb128 .LEHB5-.LFB1683
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE1683:
	.section	.text.startup
	.size	main, .-main
	.text
	.p2align 4,,15
	.globl	_Z4swapPiii
	.type	_Z4swapPiii, @function
_Z4swapPiii:
.LFB1688:
	.cfi_startproc
	movslq	%esi, %rsi
	movslq	%edx, %rdx
	leaq	(%rdi,%rsi,4), %rcx
	leaq	(%rdi,%rdx,4), %rax
	movl	(%rcx), %esi
	movl	(%rax), %edx
	movl	%edx, (%rcx)
	movl	%esi, (%rax)
	ret
	.cfi_endproc
.LFE1688:
	.size	_Z4swapPiii, .-_Z4swapPiii
	.section	.text.startup
	.p2align 4,,15
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2250:
	.cfi_startproc
	leaq	_ZStL8__ioinit(%rip), %rdi
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2250:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC4:
	.long	1232348160
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
