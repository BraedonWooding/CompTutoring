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
    add     $sp, $sp, -4
    sw      $ra, ($sp)       # save ra
    add     $sp, $sp, -4
    sw      $s0, ($sp)       # save s0

    lw      $s0, 0($a0)      # t0 = first_element = *a0 = array[0]
    beq     $a1, 1, simple_return

    add     $a0, $a0, 1      # &array[1]
    sub     $a1, $a1, 1      # length - 1
    jal     max              # max(&array[1], length - 1)

    blt     $v0, $s0, simple_return # if (max(&array[1], length - 1) > first_element)
    move    $s0, $v0

simple_return:
    move    $v0, $s0

    lw      $s0, ($sp)
    add     $sp, $sp, 4
    lw      $ra, ($sp)
    add     $sp, $sp, 4

    jr		$ra	    # return
