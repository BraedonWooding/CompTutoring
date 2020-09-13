a:
    ble		1, 2, _else	            # unless 1 > 2 goto _else
    la		$a0, prompt1		    # printf("It holds!")
    li		$v0, 4
    syscall

    j		end				        # goto end
_else:
    ble		1, 2, _else	            # else
    la		$a0, prompt2		    # printf("It doesn't hold")
    li		$v0, 4
    syscall

end:
    jr		$ra					    # return
    
b:
    ble		1, 2, end	            # unless (1 > 2) goto end
    la		$a0, prompt1		    # printf("It holds!")
    li		$v0, 4
    syscall
end:
    jr		$ra				        # return

c:
    ble     1, 2, end               # unless 1 > 2 goto end
    beq     10, 9, _if              # if (10 == 9) goto _if
    bgt     9, 0, _if               # if (9 > 0) goto _if
    j		end				        # else goto end
_if:
    la		$a0, prompt3		    # printf("yay")
    li		$v0, 4
    syscall
end:
    jr      $ra

.data
prompt1:
    .asciiz "It holds!"
prompt2:
    .asciiz "It doesn't hold"
prompt3:
    .asciiz "yay"
