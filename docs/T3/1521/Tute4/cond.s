# if (1 > 2) {
#     printf("It holds!");
# } else {
#     printf("It doesn't hold");
# }

.text
    li      $t1, 1
    li      $t2, 1
    li      $s0, 10
    li      $s1, 9

a:
# if 1 > 2 then a_if {
    bgt		$t1, $t2, a_if
    j       a_else
a_if:
    la		$a0, prompt1		# printf("It holds!")
    li      $v0, 4
    syscall
    j       a_end
# } else {
a_else:
    la		$a0, prompt2		# printf("It doesn't hold")
    li      $v0, 4
    syscall
# }
a_end:

b:
# if 1 > 2 then b_if {
    ble		$t1, $t2, b_else    # unless 1 > 2 go to b_else
b_if:
    la		$a0, prompt1		# printf("It holds!")
    li      $v0, 4
    syscall
    j       a_end
# } else {
b_else:
    la		$a0, prompt2		# printf("It doesn't hold")
    li      $v0, 4
    syscall
# }
b_end:

# if (1 > 2 && (10 == 9 || 9 > 0)) {
#     printf("yay");
# }

# if (1 > 2) {
#   if (10 == 9 || 9 > 0) {
#       printf("yay")
#   }
# } else {}

c:
# if (1 > 2) {
    ble     $1, $2, c_end       # unless 1 > 2 goto c_end
#   if (10 == 9)    goto c_process
    beq     $t0, $t1, c_process
#   else if (9 > 0) goto c_process
    bgt     $t1, $0, c_process
#   else            goto c_end
    j       c_end
#   c_process: printf("yay")
c_process:
    la		$a0, prompt3		# printf("yay")
    li      $v0, 4
    syscall

# }

c_end:

.data
prompt1: .asciiz "It holds!"
prompt2: .asciiz "It doesn't hold"
prompt3: .asciiz "yay"
