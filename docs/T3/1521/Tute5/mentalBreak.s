# ((x*x + y*y) - x*y) * z

# x^2 - y * x
# ^t0   ^t1

# ((x*x + y*y) - x*y) * z
first:

lw      $t0, x
lw      $t1, y
lw      $t2, z
mult    $t3, $t0, $t0   # tmp1 = x^2
mult    $t4, $t1, $t1   # tmp2 = y^2
mult    $t5, $t0, $t1   # tmp3 = x * y
add     $t6, $t3, $t4   # acc = x^2 + y^2
sub     $t6, $t6, $t5   # acc = x^2 + y^2 - x*y
mult    $t6, $t6, $t2   # acc = z * (x^2 + y^2 - x * y)

second:

lw      $t0, x
lw      $t1, y
mult    $t1, $t0, $t1   # y * x
mult    $t0, $t0, $t0   # x^2
sub     $t0, $t0, $t1   # x^2 - y * x

# you can always chuck this in an extra register
# to avoid the load here (giving you 8 instructions)
lw      $t1, y          
mult    $t1, $t1, $t1   # y^2
add     $t0, $t0, $t1   # x^2 - y * x + y^2

lw      $t1, z
mult    $t0, $t0, $t1   # (x^2 - y * x + y^2) * z

.data
.align 2
x:  .word 5
y:  .word 100
z:  .word 33



.data
.align 2
x:  .word 5
y:  .word 100
z:  .word 33