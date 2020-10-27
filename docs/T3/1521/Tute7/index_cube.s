nrows = 4
ncols = 4
nslices = 4
sizeOfRow = 16
sizeOfSlice = 64

index_cube:
    # $a0 = slice, $a1 = row, $a2 = col
    # ((sizeof(int) * ncols * nrows * slice) + (sizeof(int) * ncols * row) + col * sizeof(int)) + M
    mul     $t0, $a0, sizeOfSlice  # ((sizeof(int) * ncols * slice * ncols)
    mul     $t0, $t0, $a1          # ^ * row
    mul     $t1, $a1, sizeOfRow    # ((sizeof(int) * ncols * nrows)
    mul     $a2, $a2, 4
    add     $t1, $t1, $a2		   # ((sizeof(int) * ncols * nrows) + col * sizeof(int))
    la      $t2, M
    # ((sizeof(int) * ncols * nrows * slice) + (sizeof(int) * ncols * row) + col * sizeof(int))
    add     $t0, $t0, $t1 
    # M + ((sizeof(int) * ncols * nrows * slice) + (sizeof(int) * ncols * row) + col * sizeof(int))
    add     $t0, $t0, $t2
    lw      $v0, ($t0)
    jr		$ra					   # return

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
