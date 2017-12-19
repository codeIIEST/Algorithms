#PRIME FACOTRIZATION AND DIVISOR ALGORITHM
##PRIME FACTORZATION

Given a number n, write an efficient function to print all prime factors of n. For example, if the input number is 12, then output should be “2 2 3”. And if the input number is 315, then output should be “3 3 5 7”.

###Algorithm

1. While n is divisible by 2, print 2 and divide n by 2.
2. After step 1, n must be odd. Now start a loop from i = 3 to square root of n. While i divides n, print i and divide n by i, increment i by 2 and continue.
3. If n is a prime number and is greater than 2, then n will not become 1 by above two steps. So print n if it is greater than 2.

###Working

The steps 1 and 2 take care of composite numbers and step 3 takes care of prime numbers. To prove that the complete algorithm works, we need to prove that steps 1 and 2 actually take care of composite numbers. This is clear that step 1 takes care of even numbers. And after step 1, all remaining prime factor must be odd (difference of two prime factors must be at least 2), this explains why i is incremented by 2.
Now the main part is, the loop runs till square root of n not till. To prove that this optimization works, let us consider the following property of composite numbers.

Every composite number has at least one prime factor less than or equal to square root of itself.

This property can be proved using counter statement. Let a and b be two factors of n such that a*b = n. If both are greater than √n, then a.b > √n, * √n, which contradicts the expression “a * b = n”.

In step 2 of the above algorithm, we run a loop and do following in loop
* Find the least prime factor i (must be less than √n,)
* Remove all occurrences i from n by repeatedly dividing n by i.
* Repeat steps a and b for divided n and i = i + 2. The steps a and b are repeated till n becomes either 1 or a prime number.

###Time Complexity

O(n^1/2), where n is the integer.


##DIVISORS

Given a natural number n, print all distinct divisors of it.

###Algorithm

1. Iterate from i = 1 to i = root(n) + 1.
2. If i divides n, print i along with (n/i), thus reducing time.

###Time Complexity

O(n^1/2), where n is the integer.

