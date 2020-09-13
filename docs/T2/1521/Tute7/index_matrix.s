index_matrix:
    # $a0 = M, $a1 = nrows, $a2 = ncols, $a3 = row, 0($sp) = col
    lw      $t0,    0($sp)      # grab the column from the stack

    # [                    $s0 $ra $fp(old) col ... ]
    #                              ^(location) $fp(new)

    # top of the stack will contain col
    # so chuck $fp below that
    sw      $fp, -4($sp)
    # taking a reference to the address of ^^
    la      $fp, -4($sp)        # only done on load
    sw      $ra, -4($fp)
    sw      $s0, -8($fp)
    add     $sp, $sp, -12

    # sizeof(int) * (row * ncols + col) + Base
    mul     $s0, $a2, $a3
    add     $s0, $s0, $t0
    mul     $s0, $s0, 4

    add     $s0, $s0, $a0
    lw      $v0, ($s0)

    add     $sp, $sp, 12
    lw      $s0, -8($fp)
    lw      $ra, -4($fp)
    lw      $fp, -4($sp)

    jr      $ra

.data
M:
row0: .word 1, 2, 3, 4
row1: .word 3, 4, 5, 6
row2: .word 7, 8, 9, 10
row3: .word 11, 12, 13, 14

# 0  1  2  3   4  5  6  7   8  9  10 11 ...
#[1  2  3  4] [3  4  5  6] [7  8  9  10] [11  12  13  14]
