/*
 * dyn.cpp
 */
#define Version "0.1"

/*
 *
 * dyn: dynamic programming function library Implementation
 * Copyright (C) 2019 Hyeonseo Jo     https://github.com/jhcse5189
 * All rights reserved.
 *
 * Author:    Hyeonseo Jo
 *        https://github.com/jhcse5189
 * Original Date:    22 Oct 2019
 * Last modified:    22 Oct 2019
 *
 * This Implementation demonstrates the functions that can be implemented
 * via dynamic programming for fibonacci, rod cutting, maxtrix-chain
 * multiplication and longest common subsequence problems.
 */
#include "dyn.h"


/* Fibonacci sequence.
 *
 * Assume that fibonacci 0 is 0, 1 is 1.
 */


/* Recursive implementation */

Fib::Fib() : n(0) {}
Fib::Fib(int n) : n(n) {}

int Fib::recursive(int n) {
    
    if (n <= 1)
        return n;
    return Fib::recursive(n-1) + Fib::recursive(n-2); 
}