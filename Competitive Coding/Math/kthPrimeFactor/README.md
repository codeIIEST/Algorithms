Given two numbers n and k, print k-th prime factor among all prime factors of n. For example, if the input number is 15 and k is 2, then output should be “5”. And if the k is 3, then output should be “-1” (there are less than k prime factors).


A Simple Solution is to first find prime factors of n. While finding prime factors, keep track of count. If count becomes k, we return current prime factor.


