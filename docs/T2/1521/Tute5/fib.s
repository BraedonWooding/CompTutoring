fib: # (int n)
    ble		$a0, 1, simple_return	# if n <= 1 return 1
    add		$sp, $sp, -4		    # make room for ra
    sw		$ra, ($sp)
    add		$sp, $sp, -4		    # make room for s0
    sw		$s0, ($sp)
    add		$sp, $sp, -4		    # make room for a0
    sw		$a0, ($sp)

    sub		$a0, $a0, 1		        # fib(n - 1)
    jal		fib

    move 	$s0, $v0		        # save the return value
    lw      $a0, ($sp)              # restore our arg
    sub		$a0, $a0, 2		        # fib(n - 2)
    jal		fib

    add     $v0, $s0, $v0

    lw		$a0, ($sp)		        # restore a0
    add     $sp, $sp, 4
    lw		$s0, ($sp)		        # restore s0
    add     $sp, $sp, 4
    lw		$ra, ($sp)		        # restore ra
    add     $sp, $sp, 4

    jr      $ra

simple_return:
    li		$v0, 1	# return 1
    jr		$ra
