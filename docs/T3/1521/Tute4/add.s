# add 2 numbers and print the result
# takes no arguments returns an int in $v0

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

    add     $t2, $t0, $t1   # z = x + y

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