main:
    la      $t0, buf  # p = buf
    la      $t1, buf + 1024
main_write_loop:
    # if p >= &buf[1024] then main_write_loop_end
    bge		$t0, $t1, main_write_loop_end
    li		$v0, 12
    syscall             # c = getchar()
    
    beq     $v0, $0, main_write_loop_end    # EOF
    sb      $v0, $t0    # *p = c
    add     $t0, $t0, 1
    j       main_write_loop
main_write_loop_end:
    sb      $0, $t0     # *p = 0 = '\0';

    la      $t0, buf
    li      $t2, 0
len:
    lb      $t1, buf
    beq     $t1, $0, len_end                # \0
    add     $t2, $t2, 1
    add     $t0, $t0, 1
    j       len
len_end:

    jr		$ra					# jump to $ra

# AND if you want to use indexes

main:
    move 	$t0,  $0		# i = 0
while:
    bge		$t0, 1024, end	# while (i < 1024)
    li		$v0, 5		    # scanf("%d", &ch)
    syscall
    beq     $v0, $0, end
    # we need to multiply 'i' by size of the underlying data
    # in this case we have just a bunch of bytes
    # so we'll multiply it by 1
    # mult    $t0, $t0, 1     # i *= 1
    la		$t1, buf
    add		$t1, $t1, $t0     # find the address including offset
    sb		$v0, ($t1)        # buf[i] = ch
    add     $t0, $t0, 1
    j       while
end:
    la		$t1, buf
    add		$t1, $t1, $t0     # find the address including offset
    sb		$0, ($t1)         # buf[i] = '\0' = 0

    move    $t0, $0           # i = 0
len:
    la		$t1, buf
    add		$t1, $t1, $t0     # find the address including offset
    lb		$t2, ($t1)        # tmp = buf[i]
    beq     $t2, $0, end_len

    add     $t0, $t0, 1
    j		len
end_len:
    # printing out 'i' ...
    # printing out 'buf' ...

    jr      $ra

.data
buf:
.space 1025