// Two 1-d array implementation
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
#define Min(a,b)  (a<b?a:b)
#define Max(a,b)  (a<b?b:a)
#define fr(i,j,s) for(i = j ; i < s ; i++)
long long int current_dp[100002]={0};
long long int previous_dp[100002]={0};
int main(void)
{
	long long int test ,alpha , temp , lena , lenb , i, j,z,x,c ;
	char a[100001];
	char b[100001];
	cin>>test ;
	while(test--)
	{
		cin>>a;
		cin>>b;
		cin>>z;
		cin>>x;
		cin>>c;
		lena = strlen(a) ;
		lenb = strlen(b) ;
		if((lena-lenb)*z > c || (lenb-lena)*z > c )
		{
			cout<<"-1\n";
			continue ;
		}
		if( (z == 0) )
		{
			cout<<"0\n" ;
			continue ;
		}
		if( (x == 0) )
		{
			cout<<z*((lena-lenb) < 0 ? -1*(lena-lenb):(lena-lenb))<<"\n" ;
			continue ;
		}
		fr(i,0,lenb+1)
		{
			if(i > c)
				previous_dp[i] = inf ;
			else
				previous_dp[i] = i*z ;	
		}	
		fr(i,1,lena+1)
		{
			alpha = Max((i-c),0) ;
			if( alpha > 0)
			{
				current_dp[alpha-1] = inf ;
			}
			alpha -= 1 ;
			temp = Min((i+c+1),(lenb+1)); 
			fr(j,alpha+1,temp)
			{
				if(j == 0)
				{
					current_dp[j] = i*z ;
				}
				else
				{
					current_dp[j] = Min(Min(previous_dp[j] + z , current_dp[j-1] + z ) , previous_dp[j-1]+(a[i-1] == b[j-1] ? 0 : x));
				}
			}
			fr(j,alpha,temp)
			{
				previous_dp[j] = current_dp[j] ; 
			}
		}
		if(current_dp[lenb] > c)
			cout<<"-1\n";
		else
			cout<<current_dp[lenb]<<"\n";
		}	
	return 0 ;
}