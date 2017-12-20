Given a positive integer, check if the number is prime or not. A prime is a natural number greater than 1 that has no 
positive divisors other than 1 and itself.

Examples of first few prime numbers are {2, 3, 5, 7,...}

Examples:

Input:  n = 11

Output: true

Input:  n = 15

Output: false

Input:  n = 1

Output: false

A simple solution is to iterate through all numbers from 2 to n-1 and for every number check if it divides n. If we find 
any number that divides, we return false.   Instead of checking till n,  we can check till √n because a larger factor of n 
must be a multiple of smaller factor that has been already checked.  The algorithm can be improved further by observing 
that all primes are of the form 6k ± 1, with the exception of 2 and 3.  This is because all integers can  be  expressed 
as (6k + i) for some integer k and for i = ?1, 0, 1, 2, 3, or 4; 2 divides  (6k + 0),  (6k + 2),  (6k + 4); and 3 divides 
(6k + 3).  So a more efficient method is to test if n is divisible by 2 or 3,  then to check through all the numbers of 
form 6k ± 1.
