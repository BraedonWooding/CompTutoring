main:
    li		$t0, 1		        # i = $t0 = 1
outer_while:
    bgt		$t0, 10, outer_end  # unless (i <= 10) goto outer_end

    move    $t1, $0              # j = $t1 = 0
inner_while:
    bge		$t1, $t0, inner_end	# unless (j < i) goto inner_end

    li      $a0, '*'            # putchar('*')
    li      $v0, 11
    syscall

    add		$t1, $t1, 1		    # j = j + 1
    j		inner_while		    # goto inner_while
inner_end:
    li      $a0, '\n'            # putchar('\n')
    li      $v0, 11
    syscall

    add		$t0, $t0, 1		    # i = i + 1
    j		outer_while		    # goto outer_while    
outer_end:
    jr		$ra					# return
