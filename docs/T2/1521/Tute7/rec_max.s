max:
    # $a0 = a[...], $a1 = length
    lw		$v0, 0($a0)             # first_element = a[0]
    beq		$v0, 1, max_return	# if (length == 1) return a[0]

    add     $sp, $sp, -4            # 'push' ra
    sw      $ra, ($sp)
    add     $sp, $sp, -4            # 'push' s0
    sw      $s0, ($sp)
    move    $s0, $v0

    add     $a0, $a0, 4             # $a0 = &a[1]
    add     $a1, $a1, -1            # $a1 = length - 1
    jal     max                     # max(&a[1], length - 1)

    ble     $s0, $v0, skip          # if (first_element > max_so_far)
    move    $v0, $s0

skip:
    lw      $s0, ($sp)
    add     $sp, $sp, 4
    lw      $ra, ($sp)
    add     $sp, $sp, 4

max_return:
    jr      $ra
