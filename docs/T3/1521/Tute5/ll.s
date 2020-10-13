# A linked list in MIPS
# LL has next (int), data (int)
# i.e.

# struct ll {
#   struct ll *next; // which is just an int
#   int data;
# }

# Let's write our POP function just as one normally would
pop_ll: # (LL *head in a0)
    TODO

# and we'll do a proper prologue and stuff for this
apply_ll: # (a0 head, a1 fn)
    TOOD

printf_ll: # (int n)
    TODO

push_ll: # (LL *head in a0, int data in a1)
    TODO

main:
    TODO

    jr		$ra					# return

.data
arrow: .asciiz " -> "
end_arrow: .asciiz "X\n"
sum_text: .asciiz "Sum: "
sum: .word 0
