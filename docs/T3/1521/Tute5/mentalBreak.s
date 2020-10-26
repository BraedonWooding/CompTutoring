# ((x*x + y*y) - x*y) * z

    lw      $t0, x
    lw      $t2, y
    
    mul     $t1, $t0, $t2   # xy
    mul     $t0, $t0, $t0   # x^2
    sub     $t0, $t0, $t1

    mul     $t1, $t2, $t2   # y^2
    add     $t0, $t0, $t1
    
    lw      $t1, z
    mul     $t0, $t0, $t1


.data
.align 2
x:  .word 5
y:  .word 100
z:  .word 33