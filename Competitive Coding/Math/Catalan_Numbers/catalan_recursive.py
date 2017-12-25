def catalan_numbers(n):
    if n <=1 :		#The result will be 1, if the function takes an argument that's equal to or less than 1
        return 1
    res = 0		#Result has been initialised to 0
    for i in range(n):
        res += catalan_numbers(i) * catalan_numbers(n-i-1)	#The recursive function call
    return res

for i in range(5):	#Implements the algo and finds the first 5 catalan numbers
    print catalan_numbers(i)
