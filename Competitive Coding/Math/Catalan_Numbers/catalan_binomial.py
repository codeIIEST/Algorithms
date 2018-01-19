def binCoeff(n, k):	#Finds the binomial coefficient
    if (k > n - k):	#As binCoeff(n,k)=binCoeff(n,n-k)
        k = n - k
    res = 1		#Initialising Result
    for i in range(k):
        res = res * (n - i)
        res = res / (i + 1)
    return res		#The binomial coefficient is returned

def catalan(n):		#Function that finds catalan numbers
    c = binCoeff(2*n, n)	#Finding value of c by calling the binCoeff function
    return c/(n + 1)		#This is the final catalan number

if __name__=='__main__':
	print "The 10th catalan number is:",catalan(9)
