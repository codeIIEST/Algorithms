#include <bits/stdc++.h>
using namespace std;
#define Min(a,b)  (a<b?a:b)
#define fr(i,j,s) for(i = j ; i < s ; i++)
long long int dp[2002][2002]={0};
int main(void)
{
	long long int test , lena , lenb , i, j ;
	char a[20001];
	char b[20001];
	cin>>test ;
	while(test--)
	{
		cin>>a;
		cin>>b;
		lena = strlen(a) ;
		lenb = strlen(b) ;
		dp[lena+1][lenb+1];
		fr(i,0,lena+1)
		{
			fr(j,0,lenb+1)
			{	
				if( i == 0 )
				{
					dp[i][j] = j ;
				}
				else if( j == 0 )
				{
					dp[i][j] = i ;
				}
				else
				{
					dp[i][j]=Min(Min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(a[i-1]==b[j-1]?0:100));
				}
				cout<<dp[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<dp[lena][lenb]<<"\n";
	}	
	return 0 ;
}