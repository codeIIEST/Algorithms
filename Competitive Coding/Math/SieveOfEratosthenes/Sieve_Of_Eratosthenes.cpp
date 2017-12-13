#include<bits/stdc++.h>
using namespace std;

vector<int> SieveOfEratosthenes(int n)
{
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	vector<int>Primes;
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