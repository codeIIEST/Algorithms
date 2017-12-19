# Finding the largest power of 2 (most significant bit in binary form), which is less than or 
equal to the given number N.

Let’s say binary form of a N is {1111}base2 which is equal to 15.
15 = 2^4-1, where 4 is the number of bits in N.

This property can be used to find the largest power of 2 less than or equal to N. How? 
If we somehow, change all the bits which are at right side of the most significant bit of N to 1, then the number will become x + (x-1) = 2 * x -1 , where x is the required answer.
Example: 
Let’s say N = 21 = {10101}, here most significant bit is the 4th one. (counting from 0th digit) and so the answer should be 16.
So lets change all the right side bits of the most significant bit to 1. Now the number changes to 
{11111} = 31 = 2 * 16 -1 = Y (let’s say).
Now the required answer is (Y+1)>>1 or (Y+1)/2.
