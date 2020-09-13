# Big O Tool

This is a tool that is meant to help with seeing the complexity of a given chunk of code.

It'll try to guess your complexity too, it isn't very good if the complexity is O(1) since sometimes it can think its `log(n)`

> This is actually an interesting sidepoint around non analytical/theoretical solutions it is really hard to prove that the value you got was right!  Since maybe it just was so small (like `log(log(log(n)))`) that you didn't see the growth till you would have given it a much larger number.

[tool](assets/js/bigoh.html ':include :type=iframe :width=100% :height=750')

## Documentation on the tool

!> Note: I don't recommend running it on high end counts it may just crash :(.  Javascript is really slow!!!

?> If you run into any problems pop me an email at b.wooding@unsw.edu.au

Effectively it runs your program iterating over `n` setting it to `start` then multiplying it by step till it reaches `end`.  (The multiplication is just more what you want than just a plain +1 it still gives nice graphs while cutting down CPU costs).

Your graphs won't appear exactly like how you would think due to the fact the graph is most likely not perfectly aspect ratio'd.  But if you zoom out enough it should look good.

## Documentation on the language

It is almost identical to the pseudocode you'll come across in the wild with a few differences.

1. There are no functions (I may add them if people really want them)
2. Arrays/Queues/Stacks aren't created automatically also you only have access to those 3
3. There is no `pop x from S` instead you write it as `x = pop S`.  Similar for when pushing an element you write `push x S` instead of `push x onto S` (i.e. remove verbs)
4. Arithmetic and if statements should work but it's javascript so you may end up with weird stuff (I hopefully have encapsulated it enough so you don't)
5. You can call functions with/without parenthesis they should work as expected
6. Commas shouldn't be used to separate function arguments they can be used to separate expressions though i.e. `e = pop S, push e S`

The following are all the functions supported:

- `print` (followed by any number of arguments) : does nothing useful if you want to evaluate stuff
  - i.e. `print A[i] A[j]`
- `pop S` : pops from stack S
  - i.e. `pop A`
- `push elem S` : pushes onto Stack S
  - i.e. `push 5 S`
- `rand n` returns an array of size `n` with randomized members
  - i.e. `A = rand n` can be used to create arrays, stacks, or queues of size `n`
- `empty S` returns true if the given collection is empty (arrays, stacks, queues)
- `length S` returns the length of the collection
- `enqueue elem S` : enqueues value onto queue
  - i.e. `enqueue 10 Q`
- `dequeue S` : dequeues value from queue
  - i.e. `x = dequeue Q`
- `init n` creates a set / array / queue of size n with all values being 0
