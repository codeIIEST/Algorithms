
#include <bits/stdc++.h>
using namespace std;
 
/* Iterative Function to calculate (a^n)%p in O(logy) */
int power(int a, unsigned int n, int p)
{
    int res = 1;      // Initialize result
    a = a % p;  // Update 'a' if 'a' >= p
 
    while (n > 0)
    {
        // If n is odd, multiply 'a' with result
        if (n & 1)
            res = (res*a) % p;
 
        // n must be even now
        n = n>>1; // n = n/2
        a = (a*a) % p;
    }
    return res;
}
 
// If n is prime, then always returns true, If n is
// composite than returns false with high probability
// Higher value of k increases probability of correct result.

bool isPrime(unsigned int n, int k)
{
   // Corner cases
   if (n <= 1 || n == 4)  return false;
   if (n <= 3) return true;
 
   // Try k times
   while (k>0)
   {
       // Pick a random number in [2..n-2]        
       // Above corner cases make sure that n > 4
       int a = 2 + rand()%(n-4);  
 
       // Fermat's little theorem
       if (power(a, n-1, n) != 1)
          return false;
 
       k--;
    }
 
    return true;
}
 
// Driver Program
int main()
{
    int k = 3;
    isPrime(11, k)?  cout << " true\n": cout << " false\n";
    isPrime(15, k)?  cout << " true\n": cout << " false\n";
    return 0;
}


Output:

true
false
