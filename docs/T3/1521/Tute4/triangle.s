# int main (void) {
#     int i = 1;
# while_outer:
#     if (i <= 10) {
#         int j = 0;
# while_inner:
#         if (j < i) {
#             printf("*");
#             j++;
#             goto while_inner;
#         }
#         printf("\n");
#         i++;
#         goto while_outer;
#     }
#     return 0;
# }

# takes no arguments returns an int
main: # int main(void) {
    # $t0 = i $t1 = j
#     for (int i = 1; i <= 10; i++) {
    li		$t0, 1		# i = 1
main_outer:
    bgt     $t0, 10, main_outer_end # loop while (i <= 10) else main_outer_end

    move 	$t1, $0		# j = 0
#         for (int j = 0; j < i; j++) {
main_inner:
    bge     $t1, $t0, main_inner_end # loop while (j < i) else main_outer_end

    li      $a0, '*'    # putchar('*')
    li      $v0, 11
    syscall

    add     $t1, $t1, 1
    j       main_inner
#         }
main_inner_end:
    li      $a0, '\n'    # putchar('\n')
    li      $v0, 11
    syscall

    add     $t0, $t0, 1     # i++
    j       main_outer
#   }
main_outer_end:
    jr      $ra         # return 0
# }
