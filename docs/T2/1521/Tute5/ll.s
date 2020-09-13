# A linked list in MIPS
# LL has next (int), data (int)

# Let's write our POP function just as one normally would
pop_ll: # (LL *head in a0)
    lw		$v0, ($a0)		# tmp = *head;
    add		$sp, $sp, 8		# pop 8 bytes
    # warning normally we don't like just adding to the stack
    # / pushing on the stack in different functions
    jr      $ra

# and we'll do a proper prologue and stuff for this
apply_ll: # (a0 head, a1 fn)
    sw      $fp,    -4($sp)     # save fp
    la      $fp,    -4($sp)     # load the address of the top of stack
    sw      $ra,    -4($fp)
    sw      $s0,    -8($fp)
    sw      $s1,    -12($fp)
    add     $sp, $sp, -16

    move    $s0, $a0            # save variables
    move    $s1, $a1
apply_loop:
    beqz    $s0, apply_end
    lw      $a0, 4($s0)         # load data (tmp->data)
    la      $ra, apply_continue
    jr      $s1
apply_continue:
    lw      $s0, ($s0)          # tmp = tmp->next
    j       apply_loop
apply_end:

    add     $sp, $sp, 16
    lw      $s1,    -12($fp)
    lw      $s0,    -8($fp)
    lw      $ra,    -4($fp)
    lw      $fp,    -4($sp)
    jr $ra

printf_ll: # (int n)
    li		$v0, 1		# printf("%d", n)
    move    $a0, $a0    # NOT needed since already in a0
    syscall

    li      $v0, 4
    la		$a0, arrow  # printf(" -> ")
    syscall

    jr      $ra

push_ll: # (LL *head in a0, int data in a1)
    add     $sp, $sp, -8    # make room on stack for LL
    sw		$a0, 0($sp)     # store next
    sw      $a1, 4($sp)     # store data
    move 	$v0, $sp		# current address of SP is address of LL
    jr      $ra

main:
    add     $sp, $sp, -4    # ra
    sw      $ra, ($sp)
    add     $sp, $sp, -4    # s0
    sw      $s0, ($sp)

    move    $s0, $0         # head = NULL
main_loop_load:
    li      $v0, 5          # scanf("%d", &next)
    syscall
    beqz    $v0, main_loop_load_end

    move    $a0, $s0
    move    $a1, $v0
    jal     push_ll
    move    $s0, $v0        # head = push(head, next)

    j       main_loop_load
main_loop_load_end:

    move    $a0, $s0
    la      $a1, printf_ll
    jal     apply_ll

    la      $a0, end_arrow
    li      $v0, 4
    syscall

    sw      $0, sum($0)
    la      $ra, main_continue
    move    $a0, $s0
    la      $a1, local_fn
    j       apply_ll

local_fn: # (int n)
    lw      $t0, sum($0)
    add     $t0, $a0, $t0   # sum += n
    sw      $t0, sum($0)
    jr      $ra             # return

main_continue:
    la      $a0, sum_text   # printf("Sum: ")
    li      $v0, 4
    syscall

    lw      $a0, sum($0)
    li      $v0, 1
    syscall

    li      $a0, '\n'
    li      $v0, 11
    syscall

    # pop off the list
main_loop_pop:
    beqz    $s0, main_loop_pop_end  # while (head)
    move    $a0, $s0
    jal     pop_ll

    move    $s0, $v0
    j       main_loop_pop
main_loop_pop_end:

    lw      $s0, ($sp)
    add     $sp, $sp, 4
    lw      $ra, ($sp)
    add     $sp, $sp, 4

    jr		$ra					# return

.data
arrow: .asciiz " -> "
end_arrow: .asciiz "X\n"
sum_text: .asciiz "Sum: "
sum: .word 0
