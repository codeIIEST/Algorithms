Given a number n, check if it is prime or not.  This method is a probabilistic method and is based on below Fermat’s Little Theorem.

Fermat's Little Theorem:
If n is a prime number, then for every a, 1 <= a < n,

a^n-1 = 1 mod (n)
 OR 
a^n-1 % n = 1 
 

Example:

         Since 5 is prime, 2^4 ≡ 1 (mod 5) [or 2^4%5 = 1],
         
         3^4 ≡ 1 (mod 5) and 4^4 ≡ 1 (mod 5). 

         Since 7 is prime, 2^6 ≡ 1 (mod 7),
         
         3^6 ≡ 1 (mod 7), 4^6 ≡ 1 (mod 7) 
         5^6 ≡ 1 (mod 7) and 6^6 ≡ 1 (mod 7).
         
We will take help of this Fermat's Little Theorem as a function to calculate a no is prime or not.         
