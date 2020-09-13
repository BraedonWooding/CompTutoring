_add: # (int x, int y) -> int
    add $v0, $a0, $a1       # v0 = x + y
    jr  $ra                 # return v0

main:
    la		$a0, prompt		    # printf("Enter a number")
    li		$v0, 4
    syscall

    li		$v0, 5              # scanf("%d", &y);
    syscall
    move 	$t0, $v0		    # y = $v0

    la		$a0, prompt		    # printf("Enter a number")
    li		$v0, 4
    syscall

    li		$v0, 5              # scanf("%d", &x);
    syscall
    move 	$t1, $v0		    # x = $v0

    move    $a0, $t0
    move    $a1, $t1

    move    $s0, $ra            # this isn't the 'best' way of doing it
                                # but it'll be fine for now, we'll found out the
                                # stack later
    jal     _add                # add(x, y)
    nop

    move    $a0, $v0            # printf("%d", z);
    li      $v0, 1
    syscall

    li      $a0, '\n'           # putchar('\n')
    li      $v0, 11
    syscall

    move    $ra, $s0
    j $ra

.data # (rd/wr, no execute)
prompt:
    .asciiz "Enter a number: "
