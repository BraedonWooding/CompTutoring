nrows = 4
ncols = 4
nslices = 4
sizeOfRow = 16
sizeOfSlice = 64

index_cube:
    # $a0 = slice, $a1 = row, $a2 = col
    # (slice * colsize * rowsize * sizeof(int)) + (row * colsize * sizeof(int)) + col * sizeof(int)
    mul     $t0, $a0, sizeOfSlice # (slice * colsize * rowsize * sizeof(int))
    mul     $t1, $a1, sizeOfRow # (row * colsize * sizeof(int))
    mul     $t2, $a2, 4         # col * sizeof(int)

    add     $t0, $t0, $t1
    add     $t0, $t0, $t2

    la		$t3, M		        # starting offset of array M
    add     $t0, $t0, $t3
    lw      $v0, ($t0)          # cube[slice][row][col]
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
