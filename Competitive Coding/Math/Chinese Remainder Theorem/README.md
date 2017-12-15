The Chinese remainder theorem is a theorem of number theory, which states that if one knows the remainders of the Euclidean division of an 
integer n by several integers, then one can determine uniquely the remainder of the division of n by the product of these integers, under 
the condition that the divisors are pairwise coprime.
SAY.........
We are given two arrays num[0..k-1] and rem[0..k-1].
In num[0..k-1], every pair is coprime (gcd for every pair is 1).We need to find minimum positive number x such that:

     x % num[0]    =  rem[0], 
     x % num[1]    =  rem[1], 
     .......................
     x % num[k-1]  =  rem[k-1] 
     
Basically, we are given k numbers which are pairwise coprime, and given remainders of these numbers when an unknown number x is divided
by them. We need to find the minimum possible value of x that produces given remainders.

Examples:

Input:  num[] = {5, 7}, rem[] = {1, 3}

Output: 31

Explanation: 

31 is the smallest number such that:

  (1) When we divide it by 5, we get remainder 1. 
  
  (2) When we divide it by 7, we get remainder 3.

Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}

Output: 11

Explanation:

11 is the smallest number such that:

  (1) When we divide it by 3, we get remainder 2. 
  
  (2) When we divide it by 4, we get remainder 3.
  
  (3) When we divide it by 5, we get remainder 1.
  
 //////// The solution is based on below formula.\\\\\\\\\\\\


x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all but num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of pp[i] with respect to num[i]

/// I have explained the Modular multiplicative inverse method by Extended Euclidean algorithms in another file
(Named : Modular multiplicative inverse).///

///////WORKING PROCESS\\\\\\\

Example:

Let us take below example to understand the solution

   num[] = {3, 4, 5}
   
   rem[] = {2, 3, 1}
   
   prod  = 60 
   
   pp[]  = {20, 15, 12}
   
   inv[] = {2,  3,  3}  { (20X2)%3 = 1, (15X3)%4 = 1
                          (12X3)%5 = 1}

   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] + rem[2]*pp[2]*inv[2]) % prod
   
     = (2*20*2 + 3*15*3 + 1*12*3) % 60
     
     = (40 + 135 + 36) % 60
     
     = 11
     
