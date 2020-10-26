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
    li  $t0, 1       # i = 1
    lw  $t1, numbers # max = *number
    
main_loop:
    bge $t0, 10, main_loop_end  # if (i < 10)
    mul $t2, $t0, 4             # byte offset of i
    add $t3, numbers, $t2       # addr = num + offset
    lw  $t4, ($t3)              # t4 = *addr
    
    add $t0, $t0, 1             # i++
    ble $t4, $t1, main_loop     # if (numbers[i] > max)
    move $t1, $t4
    j   main_loop
    
main_loop_end:
    jr  $ra

main:
    la  $t0, numbers    # cur = number
    lw  $t1, 0($t0)     # max = *number
    
main_loop:
    bge $t0, numbers + 40, main_loop_end  # if (cur < numbers + 40)
    lw  $t2, ($t0)              # t2 = *cur

    add $t0, $t0, 4             # i++
    ble $t4, $t1, main_loop     # if (numbers[i] > max)
    move $t1, $t4
    j   main_loop
    
main_loop_end:
    jr  $ra

.data
numbers: .word 0,1,2,3,4,5,6,7,8,9
