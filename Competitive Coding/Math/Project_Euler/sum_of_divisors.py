def divisors(n): #function to find divisors of a number
	sum_digits=1	#initialising sum as 1 as 1 is a multiple of all numbers
	for i in range(2,n/2+1):	#running loop from 2 to n/2+1 as the highest possible divisor of a number is half of the num
		if(n%i==0):
			sum_digits+=i		#calculating sum of divisors
	print sum_digits		#prints sum of diviors


if __name__=='__main__':
	divisors(10000)
