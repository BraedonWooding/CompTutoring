# int max(int a[], int length) {
#     int first_element = a[0];
#     if (length == 1) {
#         return first_element;
#     } else {
#         // find max value in rest of array
#         // Recursive!
#         int max_so_far = max(&a[1], length - 1);
#         if (first_element > max_so_far) {
#             return first_element;
#         }
#         return max_so_far;
#     }
# }

max:    # int *a = $a0, int length = $a1
    # prologue
    addi    $sp, $sp, -4
    sw		$ra, 0($sp)		# save ra
    addi    $sp, $sp, -4
    sw		$s0, 0($sp)		# save s0

    lw		$s0, 0($a0)                 # first_element = a[0]
    beq     $a1, 1, simple_return       # if (length == 1) return a[0]
    
    add     $a0, $a0, 1     # a++
    sub     $a1, $a1, 1     # length--
    jal     max             # max_so_far = max(a + 1, length - 1);

    ble		$s0, $v0, epilogue	# if $t0 > $t1 then max_so_far = first_element
simple_return:
    move 	$v0, $s0		# $v0 = $s0 (prepare our return value)

epilogue:
    lw		$s0, 0($sp)		# restore $s0
    addi    $sp, $sp, 4
    lw		$ra, 0($sp)		# restore $ra
    addi    $sp, $sp, 4
    jr      $ra     # return a[0]
