#ifndef RECURSION_H
#define RECURSION_H

/**
 * Maps to the mathematical fibonacci sequence
 * as in
 
 fib(n) =
 {
    1,                       n <= 1
    fib(n - 1) + fib(n - 2), otherwise
 }

 1, 1, 2, 3, 5, 8, 13, ...
 
 Some people define fib(0) = 0
 I am not one of those people :)
 
 **/
int fib_rec(int n);

/**
 * Same as above but uses memoization
 **/
int fib_memo(int n);

/**
 * Goes opposite way :)
 **/
int fib_upwards(int n);

#endif // RECURSION_H
