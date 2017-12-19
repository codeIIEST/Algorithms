Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’ under modulo ‘m’.

The modular multiplicative inverse is an integer ‘x’ such that.

 a x ≡ 1 (mod m) 
 
The value of x should be in {0, 1, 2, … m-1}, i.e., in the ring of integer modulo m.

The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).

Examples:

Input:  a = 3, m = 11

Output: 4

Since (4x3) mod 11 = 1, 
4 is modulo inverse of 3

One might think, 15 also as a valid output as "(15x3) mod 11" 
is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not 
valid.

Input:  a = 10, m = 17

Output: 12

Since (10x12) mod 17 = 1, 12 is modulo inverse of 3

