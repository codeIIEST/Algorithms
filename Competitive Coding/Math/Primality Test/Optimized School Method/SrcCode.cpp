// A optimized school method based C++ program to check if a number is prime or not.

#include <bits/stdc++.h>
using namespace std;
 
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
 
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}
 
 
// Driver Program
int main()
{
    isPrime(23)?  cout << " true\n": cout << " false\n";//use of ternary operator
    isPrime(35)?  cout << " true\n": cout << " false\n";
    return 0;
}

Output:

true
false
