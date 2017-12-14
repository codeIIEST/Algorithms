#include<bits/stdc++.h>
using namespace std;

int MaxSumIncrsSubseq(int arr[],int n)
{
	int i,j,mx=0;
	int MSIS[n];   //An array of initial size as that of the original array to store the maximum sum of the increasing subsequence till that point.
	for(i=0;i<n;i++)
	{
		MSIS[i]=arr[i];
	}
	/* The main condition to check if the next element of the array should be considered in the maximum sum subsequence array or not , 
	   by checking the given two conditions:-
	   1.) arr[i]>arr[j]
	   2.)MSIS[i]<MSIS[j] + arr[i]
	*/
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && MSIS[i]<MSIS[j]+arr[i])
				MSIS[i]=MSIS[j]+arr[i];
		}
	}
	for(i=0;i<n;i++)
		if(mx<MSIS[i])
			mx=MSIS[i];

	return mx;       // The maximum sum of the increasing subsequence.
}

int main()
{
	int arr[] = {2,3,100,5,6,101,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int ans = MaxSumIncrsSubseq(arr,n);
	cout<<ans<<"\n";
	return 0;
}