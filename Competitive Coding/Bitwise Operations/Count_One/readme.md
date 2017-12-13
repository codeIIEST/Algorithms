#Program to count the no of 1's  in the binary representation of a given decimal number using Bitwise Operations.

Algorithm::Let,x be the given decimal number. The binary representation of x and x-1 will have all bits equal except the righmost 1 in x and all digits after the 
rightmost digit are flipped. So if we perform x&(x-1) and store the result in x, the number of 1's in x gets reduced by 1.
So we can count how many times the operation can be performed and keep track of it using any counter variable.
Let. x=5
	Binary Representation of 5 is 101
	x=x&(x-1)=101 & 100 = 100
	x=x&(x-1)=100 & 011=000

So, the operation got performed for 2 times until x became 0. So, the number of 1's in x is 2.
