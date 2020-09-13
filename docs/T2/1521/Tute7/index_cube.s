index_cube:
  # $a0 = C, $a1 = nrows, $a2 = ncols, $a3 = nslices, 0($sp) = row, 4($sp) = col, 8($sp) = slice
  lw      $t0,    0($sp)      # grab the row from the stack
  lw      $t1,    4($sp)      # grab the column from the stack
  lw      $t2,    8($sp)      # grab the slice from the stack
  # [                      row, col, slice ]
  #                        ^

  # top of the stack will contain col
  # so chuck $fp below that
  sw      $fp, -4($sp)
  # [                s0, ra, old_fp, row, col, slice ]
  #                          ^fp
  # taking a reference to the address of ^^
  la      $fp, -4($sp)        # only done on load
  sw      $ra, -4($fp)
  sw      $s0, -8($fp)
  add     $sp, $sp, -12

  # sizeof(int) * (ncols * nrows * slice) + Base
  # later on... + sizeof(int) * (ncols * row + col)
  mul     $s0, $a1, $a2
  mul     $s0, $s0, $t2
  mul     $s0, $s0, 4
  add     $s0, $a0, $s0

  move    $a0, $s0
  move    $a1, $a1
  move    $a2, $a2
  move    $a3, $t0
  add     $sp, $sp, -4
  sw      $t1, 0($sp)

  jal     index_matrix

  add     $sp, $sp, 4
  add     $sp, $sp, 12
  lw      $s0, -8($fp)
  lw      $ra, -4($fp)
  lw      $fp, -4($sp)

  jr      $ra

.data
cube:
slice0:
  row00:
    col000: .word 2
    col001: .word 4
    col002:
    col003:
  row01:
    ...
  row02:
    col020:
    col021:
    col022:
    col023:
  row03:
    ...
slice1:
  row10:
    col100:
    col101:
    col102:
    col103:
  row11:
    ...
  row12:
    col120:
    col121:
    col122:
    col123:
  row13:
    ...
slice2:
  ...
slice3:
  ...
