#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i;
	printf("Enter a number:\n");
	scanf("%d",&n);
	printf("Enter bit to be checked:\n");
	scanf("%d",&i);
    if( n & (1 << i) )
     printf("The %dth bit is set in %d",i,n);
    else
     printf("The %dth bit is not set in %d",i,n);
    return 0;
}