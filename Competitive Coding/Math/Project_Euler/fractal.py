def factorial(n): #function to calculate factorial
	fact=1		#initialising value of fact to 1 as 1! = 1
	for i in range(2,n+1):
		fact *= i	#Calculating factorial
	return fact

if __name__=='__main__':
	val = factorial(100)	#Finding value of 100!
	sum_digits=0		#initialising sum_digits=0
	for i in range(0,len(str(val))):	#converting value of 100! to string
		sum_digits +=int(str(val)[i])		#Adding each digit one by one in a loop to calculate sum of digits of 100!
	print sum_digits
