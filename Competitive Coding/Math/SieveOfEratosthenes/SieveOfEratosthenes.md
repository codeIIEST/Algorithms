This is the famous algorithm to find the prime numbers from '1' to 'n'.
It uses a logic that if a number 'p' is prime , then the numbers 2*p, 3*p, 4*p, .... are not prime.
Suppose we have p as 2, and we know 2 is a prime number, then all its multiple, which are 4,6,8,10,.... must not be prime as they have 2 as a factor other then 1 and the number itself.
Similarly, for all other number we can do that, and in the end all the numbers which are marked 'True' in the boolean array will be prime.

The complexity of this algorithm is O(N log(logN)).
