#include<bits/stdc++.h>
using namespace std;

vector<int> SieveOfEratosthenes(int n)
{
	bool prime[n+1];           //To mark those numbers which are prime, prime numbers will be marked by a 'True'
	memset(prime,true,sizeof(prime));
	vector<int>Primes;
	/*
		In this nested loop , we start from the value 2, and marked all its multiple which are less then or equal to n,
		similarly for 3,4,5....upto n. The logic is simple, since every number which are multiple of 2 are having 2 as a 
		factor other then 1 and the number itself, similarly for all other numbers.
	*/
	for(int p=2;p*p<=n;p++)    
	{
		if(prime[p]==true)
		{
			for(int i=p*2;i<=n;i+=p)
			{
				prime[i]=false;
			}
		}
	}
	/* Pushing all the prime numbers in one container. */
	for(int p=2;p<=n;p++)
	{
		if(prime[p])
		{
			Primes.push_back(p);
		}	
	}
	return Primes;
}

int main()
{
	int n;
	cout<<"Enter the number upto which prime numbers are to be found\n";
	cin>>n;
	vector<int> result;
	result = SieveOfEratosthenes(n);
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<" ";
	}
	cout<<"\n";
}