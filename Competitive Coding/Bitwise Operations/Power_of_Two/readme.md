#Check whether a given number of power of 2 using Bitwise Operations
 
Consider a number x that we need to check for being a power for 2. Now think about the binary representation of (x-1). 
(x-1) will have all the bits same as x, except for the rightmost 1 in x and all the bits to the right of the rightmost 1.
Let, x = 4 = (100)2
	 x - 1 = 3 = (011)2
Let, x = 6 = (110)2

	 x - 1 = 5 = (101)2
	 where ()2 represents the binary representation of a number.

The binary representation of x and x-1 will have all bits equal except the righmost 1 in x and all digits after the 
rightmost digit are flipped. So if we perform x&(x-1) and store the result in x, the number of 1's in x gets reduced by 1.

Now, for all numbers which are power of 2, there is only one 1 and if we perform x&(x-1), we will get 0.
Example::x=4=(100)2 
	 x&(x-1)=100 & 011=0
	 Hence, 4 is a power of two.


