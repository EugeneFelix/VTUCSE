	.text
	.file	"arrayOps.c"
	.globl	main                            // -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   // @main
	.cfi_startproc
// %bb.0:
	sub	sp, sp, #48                     // =48
	stp	x29, x30, [sp, #32]             // 16-byte Folded Spill
	add	x29, sp, #32                    // =32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	mov	w8, #1
	stur	w8, [x29, #-8]
.LBB0_1:                                // =>This Inner Loop Header: Depth=1
	adrp	x0, .L.str
	add	x0, x0, :lo12:.L.str
	bl	printf
	adrp	x0, .L.str.1
	add	x0, x0, :lo12:.L.str.1
	bl	printf
	adrp	x0, .L.str.2
	add	x0, x0, :lo12:.L.str.2
	bl	printf
	adrp	x0, .L.str.3
	add	x0, x0, :lo12:.L.str.3
	bl	printf
	adrp	x0, .L.str.4
	add	x0, x0, :lo12:.L.str.4
	bl	printf
	adrp	x0, .L.str.5
	add	x0, x0, :lo12:.L.str.5
	bl	printf
	adrp	x0, .L.str.6
	add	x0, x0, :lo12:.L.str.6
	bl	printf
	adrp	x0, .L.str.7
	add	x0, x0, :lo12:.L.str.7
	sub	x1, x29, #12                    // =12
	bl	scanf
	ldur	w8, [x29, #-12]
	subs	w8, w8, #1                      // =1
                                        // kill: def $x8 killed $w8
	str	x8, [sp, #8]                    // 8-byte Folded Spill
	subs	x8, x8, #4                      // =4
	b.hi	.LBB0_8
// %bb.2:                               //   in Loop: Header=BB0_1 Depth=1
	ldr	x11, [sp, #8]                   // 8-byte Folded Reload
	adrp	x10, .LJTI0_0
	add	x10, x10, :lo12:.LJTI0_0
.Ltmp0:
	adr	x8, .Ltmp0
	ldrsw	x9, [x10, x11, lsl #2]
	add	x8, x8, x9
	br	x8
.LBB0_3:                                //   in Loop: Header=BB0_1 Depth=1
	bl	create
	b	.LBB0_9
.LBB0_4:                                //   in Loop: Header=BB0_1 Depth=1
	bl	display
	b	.LBB0_9
.LBB0_5:                                //   in Loop: Header=BB0_1 Depth=1
	bl	insert
	b	.LBB0_9
.LBB0_6:                                //   in Loop: Header=BB0_1 Depth=1
	bl	delete
	b	.LBB0_9
.LBB0_7:
	mov	w0, wzr
	bl	exit
.LBB0_8:                                //   in Loop: Header=BB0_1 Depth=1
	adrp	x0, .L.str.8
	add	x0, x0, :lo12:.L.str.8
	bl	printf
.LBB0_9:                                //   in Loop: Header=BB0_1 Depth=1
	b	.LBB0_1
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
	.section	.rodata,"a",@progbits
	.p2align	2
.LJTI0_0:
	.word	.LBB0_3-.Ltmp0
	.word	.LBB0_4-.Ltmp0
	.word	.LBB0_5-.Ltmp0
	.word	.LBB0_6-.Ltmp0
	.word	.LBB0_7-.Ltmp0
                                        // -- End function
	.text
	.globl	create                          // -- Begin function create
	.p2align	2
	.type	create,@function
create:                                 // @create
	.cfi_startproc
// %bb.0:
	sub	sp, sp, #448                    // =448
	stp	x29, x30, [sp, #416]            // 16-byte Folded Spill
	str	x28, [sp, #432]                 // 8-byte Folded Spill
	add	x29, sp, #416                   // =416
	.cfi_def_cfa w29, 32
	.cfi_offset w28, -16
	.cfi_offset w30, -24
	.cfi_offset w29, -32
	adrp	x0, .L.str.9
	add	x0, x0, :lo12:.L.str.9
	bl	printf
	adrp	x0, .L.str.7
	add	x0, x0, :lo12:.L.str.7
	sub	x1, x29, #4                     // =4
	bl	scanf
	adrp	x0, .L.str.10
	add	x0, x0, :lo12:.L.str.10
	bl	printf
	stur	wzr, [x29, #-8]
.LBB1_1:                                // =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-8]
	ldur	w9, [x29, #-4]
	subs	w8, w8, w9
	b.ge	.LBB1_4
// %bb.2:                               //   in Loop: Header=BB1_1 Depth=1
	ldursw	x9, [x29, #-8]
	add	x8, sp, #8                      // =8
	add	x1, x8, x9, lsl #2
	adrp	x0, .L.str.7
	add	x0, x0, :lo12:.L.str.7
	bl	scanf
// %bb.3:                               //   in Loop: Header=BB1_1 Depth=1
	ldur	w8, [x29, #-8]
	add	w8, w8, #1                      // =1
	stur	w8, [x29, #-8]
	b	.LBB1_1
.LBB1_4:
	str	wzr, [sp, #4]
.LBB1_5:                                // =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	ldur	w9, [x29, #-4]
	subs	w8, w8, w9
	b.ge	.LBB1_8
// %bb.6:                               //   in Loop: Header=BB1_5 Depth=1
	ldrsw	x9, [sp, #4]
	add	x8, sp, #8                      // =8
	ldr	w1, [x8, x9, lsl #2]
	adrp	x0, .L.str.11
	add	x0, x0, :lo12:.L.str.11
	bl	printf
// %bb.7:                               //   in Loop: Header=BB1_5 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1                      // =1
	str	w8, [sp, #4]
	b	.LBB1_5
.LBB1_8:
	ldur	w8, [x29, #-8]
	add	w9, w8, #1                      // =1
	stur	w9, [x29, #-8]
	str	w8, [sp]
	ldr	x28, [sp, #432]                 // 8-byte Folded Reload
	ldp	x29, x30, [sp, #416]            // 16-byte Folded Reload
	add	sp, sp, #448                    // =448
	ret
.Lfunc_end1:
	.size	create, .Lfunc_end1-create
	.cfi_endproc
                                        // -- End function
	.globl	display                         // -- Begin function display
	.p2align	2
	.type	display,@function
display:                                // @display
	.cfi_startproc
// %bb.0:
	sub	sp, sp, #448                    // =448
	stp	x29, x30, [sp, #416]            // 16-byte Folded Spill
	str	x28, [sp, #432]                 // 8-byte Folded Spill
	add	x29, sp, #416                   // =416
	.cfi_def_cfa w29, 32
	.cfi_offset w28, -16
	.cfi_offset w30, -24
	.cfi_offset w29, -32
	stur	wzr, [x29, #-8]
	str	wzr, [sp, #4]
.LBB2_1:                                // =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #4]
	ldur	w9, [x29, #-8]
	subs	w8, w8, w9
	b.ge	.LBB2_4
// %bb.2:                               //   in Loop: Header=BB2_1 Depth=1
	ldrsw	x9, [sp, #4]
	add	x8, sp, #8                      // =8
	ldr	w1, [x8, x9, lsl #2]
	adrp	x0, .L.str.11
	add	x0, x0, :lo12:.L.str.11
	bl	printf
// %bb.3:                               //   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #4]
	add	w8, w8, #1                      // =1
	str	w8, [sp, #4]
	b	.LBB2_1
.LBB2_4:
	ldur	w8, [x29, #-4]
	add	w9, w8, #1                      // =1
	stur	w9, [x29, #-4]
	str	w8, [sp]
	ldr	x28, [sp, #432]                 // 8-byte Folded Reload
	ldp	x29, x30, [sp, #416]            // 16-byte Folded Reload
	add	sp, sp, #448                    // =448
	ret
.Lfunc_end2:
	.size	display, .Lfunc_end2-display
	.cfi_endproc
                                        // -- End function
	.globl	insert                          // -- Begin function insert
	.p2align	2
	.type	insert,@function
insert:                                 // @insert
	.cfi_startproc
// %bb.0:
	sub	sp, sp, #464                    // =464
	stp	x29, x30, [sp, #432]            // 16-byte Folded Spill
	str	x28, [sp, #448]                 // 8-byte Folded Spill
	add	x29, sp, #432                   // =432
	.cfi_def_cfa w29, 32
	.cfi_offset w28, -16
	.cfi_offset w30, -24
	.cfi_offset w29, -32
	stur	wzr, [x29, #-8]
	adrp	x0, .L.str.12
	add	x0, x0, :lo12:.L.str.12
	bl	printf
	adrp	x0, .L.str.7
	add	x0, x0, :lo12:.L.str.7
	str	x0, [sp, #8]                    // 8-byte Folded Spill
	sub	x1, x29, #4                     // =4
	bl	scanf
	adrp	x0, .L.str.13
	add	x0, x0, :lo12:.L.str.13
	bl	printf
	ldr	x0, [sp, #8]                    // 8-byte Folded Reload
	sub	x1, x29, #16                    // =16
	bl	scanf
	ldur	w8, [x29, #-8]
	subs	w8, w8, #1                      // =1
	stur	w8, [x29, #-12]
.LBB3_1:                                // =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-12]
	ldur	w9, [x29, #-4]
	subs	w8, w8, w9
	b.lt	.LBB3_4
// %bb.2:                               //   in Loop: Header=BB3_1 Depth=1
	ldursw	x8, [x29, #-12]
	add	x9, sp, #16                     // =16
	ldr	w8, [x9, x8, lsl #2]
	ldur	w10, [x29, #-12]
	add	w10, w10, #1                    // =1
	str	w8, [x9, w10, sxtw #2]
// %bb.3:                               //   in Loop: Header=BB3_1 Depth=1
	ldur	w8, [x29, #-12]
	subs	w8, w8, #1                      // =1
	stur	w8, [x29, #-12]
	b	.LBB3_1
.LBB3_4:
	ldur	w8, [x29, #-16]
	ldursw	x10, [x29, #-4]
	add	x9, sp, #16                     // =16
	str	w8, [x9, x10, lsl #2]
	ldur	w8, [x29, #-8]
	add	w8, w8, #1                      // =1
	stur	w8, [x29, #-8]
	ldr	x28, [sp, #448]                 // 8-byte Folded Reload
	ldp	x29, x30, [sp, #432]            // 16-byte Folded Reload
	add	sp, sp, #464                    // =464
	ret
.Lfunc_end3:
	.size	insert, .Lfunc_end3-insert
	.cfi_endproc
                                        // -- End function
	.globl	delete                          // -- Begin function delete
	.p2align	2
	.type	delete,@function
delete:                                 // @delete
	.cfi_startproc
// %bb.0:
	sub	sp, sp, #448                    // =448
	stp	x29, x30, [sp, #416]            // 16-byte Folded Spill
	str	x28, [sp, #432]                 // 8-byte Folded Spill
	add	x29, sp, #416                   // =416
	.cfi_def_cfa w29, 32
	.cfi_offset w28, -16
	.cfi_offset w30, -24
	.cfi_offset w29, -32
	stur	wzr, [x29, #-8]
	adrp	x0, .L.str.14
	add	x0, x0, :lo12:.L.str.14
	bl	printf
	adrp	x0, .L.str.7
	add	x0, x0, :lo12:.L.str.7
	sub	x1, x29, #4                     // =4
	bl	scanf
	ldursw	x9, [x29, #-4]
	mov	x8, sp
	ldr	w8, [x8, x9, lsl #2]
	stur	w8, [x29, #-16]
	ldur	w8, [x29, #-4]
	stur	w8, [x29, #-12]
.LBB4_1:                                // =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-12]
	ldur	w9, [x29, #-8]
	subs	w9, w9, #1                      // =1
	subs	w8, w8, w9
	b.ge	.LBB4_4
// %bb.2:                               //   in Loop: Header=BB4_1 Depth=1
	ldur	w8, [x29, #-12]
	add	w8, w8, #1                      // =1
	mov	x9, sp
	ldr	w8, [x9, w8, sxtw #2]
	ldursw	x10, [x29, #-12]
	str	w8, [x9, x10, lsl #2]
// %bb.3:                               //   in Loop: Header=BB4_1 Depth=1
	ldur	w8, [x29, #-12]
	add	w8, w8, #1                      // =1
	stur	w8, [x29, #-12]
	b	.LBB4_1
.LBB4_4:
	ldur	w8, [x29, #-8]
	subs	w8, w8, #1                      // =1
	stur	w8, [x29, #-8]
	ldur	w1, [x29, #-16]
	adrp	x0, .L.str.15
	add	x0, x0, :lo12:.L.str.15
	bl	printf
	ldr	x28, [sp, #432]                 // 8-byte Folded Reload
	ldp	x29, x30, [sp, #416]            // 16-byte Folded Reload
	add	sp, sp, #448                    // =448
	ret
.Lfunc_end4:
	.size	delete, .Lfunc_end4-delete
	.cfi_endproc
                                        // -- End function
	.type	.L.str,@object                  // @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"\t\tMenu\n"
	.size	.L.str, 8

	.type	.L.str.1,@object                // @.str.1
.L.str.1:
	.asciz	"\t1.CREATE\n"
	.size	.L.str.1, 11

	.type	.L.str.2,@object                // @.str.2
.L.str.2:
	.asciz	"\t2.DISPLAY\n"
	.size	.L.str.2, 12

	.type	.L.str.3,@object                // @.str.3
.L.str.3:
	.asciz	"\t3.INSERT\n"
	.size	.L.str.3, 11

	.type	.L.str.4,@object                // @.str.4
.L.str.4:
	.asciz	"\t4.DELETE\n"
	.size	.L.str.4, 11

	.type	.L.str.5,@object                // @.str.5
.L.str.5:
	.asciz	"\t5.EXIT\n"
	.size	.L.str.5, 9

	.type	.L.str.6,@object                // @.str.6
.L.str.6:
	.asciz	"\n\tENTER YOUR CHOICE:\t\n"
	.size	.L.str.6, 23

	.type	.L.str.7,@object                // @.str.7
.L.str.7:
	.asciz	"%d"
	.size	.L.str.7, 3

	.type	.L.str.8,@object                // @.str.8
.L.str.8:
	.asciz	"\nInvalid choice:\n"
	.size	.L.str.8, 18

	.type	.L.str.9,@object                // @.str.9
.L.str.9:
	.asciz	"\nEnter the size of the array elements:\t"
	.size	.L.str.9, 40

	.type	.L.str.10,@object               // @.str.10
.L.str.10:
	.asciz	"\nEnter the elements for the array:\n"
	.size	.L.str.10, 36

	.type	.L.str.11,@object               // @.str.11
.L.str.11:
	.asciz	"\n\t\t%d\n"
	.size	.L.str.11, 7

	.type	.L.str.12,@object               // @.str.12
.L.str.12:
	.asciz	"\nEnter the position for the new element:\t"
	.size	.L.str.12, 42

	.type	.L.str.13,@object               // @.str.13
.L.str.13:
	.asciz	"\nEnter the element to be inserted :\t"
	.size	.L.str.13, 37

	.type	.L.str.14,@object               // @.str.14
.L.str.14:
	.asciz	"\nEnter the position of the element to be deleted:\t"
	.size	.L.str.14, 51

	.type	.L.str.15,@object               // @.str.15
.L.str.15:
	.asciz	"\nThe deleted element is %d"
	.size	.L.str.15, 27

	.ident	"clang version 13.0.0"
	.section	".note.GNU-stack","",@progbits
