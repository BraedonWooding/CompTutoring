main:
    move 	$t0,  $0		# i = 0
while:
    bge		$t0, 1024, end	# while (i < 1024)
    li		$v0, 5		    # scanf("%d", &ch)
    syscall
    beqz    $v0, end
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
    beqz    $t2, end_len

    add     $t0, $t0, 1
    j		len
end_len:
    # printing out 'i' ...
    # printing out 'buf' ...

    jr      $ra

.data
buf:
.space 1025