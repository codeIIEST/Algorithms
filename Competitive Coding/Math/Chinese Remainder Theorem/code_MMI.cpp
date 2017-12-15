// Iterative C++ program to find modular inverse using extended Euclid algorithm.
// Returns modulo inverse of a with respect to m using extended Euclid Algorithm.
//Time Complexity of this method is O(Log m).
// Assumption: a and m are coprimes, i.e., gcd(a, m) = 1

#include <stdio.h>
int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}
 
// Main method
int main()
{
    int a = 3, m = 11;
 
    printf("Modular multiplicative inverse is %d\n",
          modInverse(a, m));
    return 0;
}

Output:
Modular multiplicative inverse is 4.
