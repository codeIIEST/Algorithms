#CALCULATING GCD AND LCM USING THREE DIFFERENT APPROACHES
##Using Euclid's Algorithm

This algorithm works on the famous **Euclid's Algorithm** which states that 'GCD(m,n) = GCD(n%m , m)' and 'GCD(0,m) = m'.  
It is coded in a recurisve manner.

LCM calculation has one common formula, namely, 'LCM(m,n) = (m*n)/GCD(m,n)'.

##Using Extended Euclid's Algorithm

The Euclid's Extended Algorithm states that there exists two integers x and y such that 'mx + ny = GCD(m,n)'.  
This algorithm finds the GCD of the integers along with above said integers.

##Using Steins Algorithm

Stein’s algorithm or binary GCD algorithm is an algorithm that computes the greatest common divisor of two non-negative integers. Stein’s algorithm replaces division with arithmetic shifts, comparisons, and subtraction.

The algorithm:

1. If both a and b are 0, gcd is zero gcd(0, 0) = 0.
2. Gcd(a, 0) = a and gcd(0, b) = b because everything divides 0.
3. If a and b are both even, gcd(a, b) = 2*gcd(a/2, b/2) because 2 is a common divisor. Multiplication with 2 can be done with bitwise shift operator.
4. If a is even and b is odd, gcd(a, b) = gcd(a/2, b). Similarly, if a is odd and b is even, then gcd(a, b) = gcd(a, b/2). It is because 2 is not a common divisor.
5. If both a and b are odd, then gcd(a, b) = gcd(|a-b|/2, b). Note that difference of two odd numbers is even
6. Repeat steps 3–5 until a = b, or until a = 0. In either case, the GCD is power(2, k) * b, where power(2, k) is 2 raise to the power of k and k is the number of common factors of 2 found in step 2.



