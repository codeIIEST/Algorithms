package Euler
class P21
{ //Begin class


	/***** Function to calculate the sum of proper divisors or factors *****/
	public static int sumFactors(int num)
	{ //Begin sumFactors()
		int sum = 0;
		
		for(int i = 1; i<num; i++)
		{ //Begin for
			if(num % i == 0)
				sum += i;
		} //End for
		
		return sum;
	} //End sumFactors()
	
	
	
	
	public static void main(String args[])
	{ //Begin main()
		int sum_amicable = 0; 
		int x = 0; 
		int y = 0;
		
		
		for(int n = 1; n<=10000; n++)
		{ //Begin for
			
			x = sumFactors(n); //Sum of factors or divisors of n
			y = sumFactors(x); //Sum of factors or divisors of x
						
						
			/*** 
			1. Checking if the number is not equal to sum of its factors and if the number is equal to y(sum of factors of x) then the number is added to the sum of amicable numbers
			
			2. The other number of the amicable pair is added when it appears in the loop later and checking is done for it		***/
			
			if((n != x) && (n == y))  
				sum_amicable += n;

		} //End for
		
		System.out.println("Sum of amicable numbers less than 10000 is:\t"+sum_amicable);
	} //End main()
} //End class
