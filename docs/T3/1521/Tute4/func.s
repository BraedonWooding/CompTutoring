# add 2 numbers and print the result
# takes no arguments returns an int in $v0

add_fn: # (int x, int y) -> int
    add     $v0, $a0, $a1   # $v0 = x + y
    jr      $ra             # return $v0

.text
main: # int main(void) {
    # $t0 x, $t1 y, $t2 z;
    la		$a0, prompt	    # printf("Enter a number")
    li		$v0, 4		    # select the printf syscall
    syscall                 # executing the above command

    li      $v0, 5          # scanf("%d", &x)
    syscall
    move 	$t0, $v0		# x = $v0

    la		$a0, prompt	    # printf("Enter a number")
    li		$v0, 4
    syscall

    li      $v0, 5          # scanf("%d", &y)
    syscall
    move 	$t1, $v0		# y = $v0

    move    $a0, $t0
    move    $a1, $t1
    move    $s0, $ra        # temporarily store $ra
    jal     add_fn          # add_fn(x, y)
    move    $t2, $v0
    move    $ra, $s0        # restore $ra

    move    $a0, $t2        # printf("%d", z)
    li      $v0, 1
    syscall

    li      $a0, '\n'       # putchar('\n')
    li      $v0, 11
    syscall

    jr		$ra			    # return 0
# }

.data # rd/wr no execute
prompt:
    .asciiz "Enter a number: "
