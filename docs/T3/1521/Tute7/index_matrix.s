nrows = 4
ncols = 4
sizeOfRow = 16

index_matrix:
    # $a0 = row, $a1 = col
    # ((sizeof(int) * ncols * row) + col * sizeof(int)) + M
    mul     $t0, $a0, sizeOfRow    # nrows * row * sizeof(int)
    mul     $a1, $a1, 4            # sizeof(int) * col
    add     $t0, $t0, $a1		   # ((sizeof(int) * ncols * row) + col * sizeof(int))
    la      $t1, M
    add     $t0, $t0, $t1          # ((sizeof(int) * ncols * row) + col * sizeof(int)) + M
    lw      $v0, ($t0)
    jr		$ra					   # return

.data
M:
row0:
    col00: .word 1
    col01: .word 2
    col02: .word 3
    col03: .word 4
row1:
    col10: .word 5
    col11: .word 6
    col12: .word 7
    col13: .word 8
row2:
    col20: .word 9
    col21: .word 10
    col22: .word 11
    col23: .word 12
row3:
    col30: .word 13
    col31: .word 14
    col32: .word 15
    col33: .word 16
# ...

# [ 1 2 3 4 ] [ 3 4 5 6 ] [ 7 8 9 10 ] ...
