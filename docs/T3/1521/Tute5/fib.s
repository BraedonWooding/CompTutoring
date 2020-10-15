fib: # (int n)
    # $a0 = n
    # $v0 = return 1 OR return Fib(n - 1) + Fib(n - 2)
    ble     $a0, 1, simple_return
    add     $sp, $sp, -4        # make room for $ra
    sw      $ra, 0($sp)         # save $ra
    add     $sp, $sp, -4        # make room for $a0
    sw      $a0, 0($sp)         # save $a0 (n)
    add     $sp, $sp, -4        # make room for $s0
    sw      $s0, 0($sp)         # save $s0 fib(n - 1)

    sub     $a0, $a0, 1         # fib(n - 1)
    jal     fib
    move    $s0, $v0           # $s0 = $v0

    lw      $a0, 4($sp)         # n = original value
    sub     $a0, $a0, 2
    jal     fib

    add     $v0, $s0, $v0       # return fib(n - 1) + fib(n - 2)

    lw      $s0, 0($sp)         # save $s0 (fib(n - 1))
    add     $sp, $sp, -4        # make room for $s0
    lw      $a0, 0($sp)         # save $a0 (n)
    add     $sp, $sp, 4         # make room for $a0
    lw      $ra, 0($sp)         # save $ra
    add     $sp, $sp, 4         # make room for $ra    

    jr      $ra

simple_return:
    li      $v0, 1
    jr      $ra
