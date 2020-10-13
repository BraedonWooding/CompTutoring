# int main(void) {
#     int i;
#     int max;
#     int numbers[10] = {0,1,2,3,4,5,6,7,8,9};

#     i = 1;
#     max = numbers[0];
#     while (i < 10) {
#         // Is there a way to avoid this branch?
#         // look at SLT/SLTI and SLTIU !!
#         if (numbers[i] > max) max = numbers[i];
#         i++;
#     }
# }

main:
    la		$t2, numbers
    
    li      $t0, 1  # i = 1
    lw      $t1, 0($t2)
main_loop_lt_than_10:
    bge     $t0, 10, main_loop_end

    # compute numbers + i
    add		$t3, $t2, $t0
    lw      $t3, 0($t3)
    ble     $t3, $t1, main_loop_continue
    move    $t1, $t3

main_loop_continue:    
    add     $t0, $t0, 1
    j       main_loop_lt_than_10
main_loop_end:

# using a pointer

main:
    la		$t0, numbers        # cur = first address initially
    la      $t2, numbers + 10   # last address
    lw      $t1, 0($t2)         # max
main_loop_lt_than_10:
    bge     $t0, $t2, main_loop_end

    lw      $t3, 0($t0)                     # t3 = *cur
    ble     $t3, $t1, main_loop_continue    # if (*cur > max) max = *cur
    move    $t1, $t3

main_loop_continue:
    add     $t0, $t0, 4                     # (void*)(cur) + 4
    j       main_loop_lt_than_10
main_loop_end:

.data
numbers: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
