# A linked list in MIPS
# LL has next (int), data (int)
# i.e.

# struct ll {
#   struct ll *next; // which is just an int
#   int data;
# }

# Let's write our POP function just as one normally would
pop_ll: # (LL *head in a0)
    lw      $v0, $a0        # *head (head->next)
    add     $sp, $sp, 8     # pop head
    jr		$ra				# return head->next

push_ll: # (LL *head in a0, int data in a1)
    add     $sp, $sp, -8    # push head
    sw      $a0, 0($sp)     # cur->head = head
    sw      $a1, 4($sp)     # cur->data = dead
    move    $v0, $sp
    jr      $ra

# and we'll do a proper prologue and stuff for this
apply_ll: # (a0 head, a1 fn)
    # prologue
    add     $sp, $sp, -4    #
    sw      $ra, 0($sp)     # save ra
    add     $sp, $sp, -4    #
    sw      $s0, 0($sp)     # save s0 (a0)
    add     $sp, $sp, -4    #
    sw      $s1, 0($sp)     # save s1 (a1)
    
    move    $s0, $a0
    move    $s1, $a1

apply_loop:
    beq     $s0, $0, apply_loop_end # while (tmp)
    lw      $a0, 4($s0)     # tmp->data
    la      $ra, apply_loop_continue
    jr      $s1
apply_loop_continue:
    lw      $s0, 0($s0)     # tmp = tmp->data
    j		apply_loop
apply_loop_end:
    
    lw      $s1, 0($sp)     # restore s1 (a1)
    add     $sp, $sp, 4     #
    lw      $s0, 0($sp)     # restore s0 (a0)
    add     $sp, $sp, 4     #
    lw      $ra, 0($sp)     # restore ra
    add     $sp, $sp, 4     #

printf_ll: # (int n)
    li      $v0, 1      # printf("%d", n)
    syscall # n is already in a0

    li      $v0, 4      # printf(" -> ")
    la      $a0, arrow
    syscall

    jr      $ra

main:
    add     $sp, $sp, -4
    sw      $ra, ($sp)
    add     $sp, $sp, -4
    sw      $s0, ($sp)

    move    $s0, $0    # head = NULL
main_loop_load:
    li      $v0, 5     # next = get_int()
    syscall
    beq     $v0, $0, main_loop_load_end

    move    $a0, $s0
    move    $a1, $v0
    jal     push_ll

    j       main_loop_load
main_loop_load_end:

    move    $a0, $s0
    la      $a1, printf_ll
    jal     apply_ll

    la      $a0, end_arrow
    li      $v0, 4
    syscall

main_loop_pop:
    beq     $s0, $0, main_loop_load_end  # while (head)
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
