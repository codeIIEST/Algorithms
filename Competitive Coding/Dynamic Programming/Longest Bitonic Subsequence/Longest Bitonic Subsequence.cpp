//C++ program to find the longest bitonic sequence.
//A bitonic sequence is a sequence which increases first then decreases.
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;//n would store the size of the array.
	cout<<"Enter the length of the array : ";
	cin>>n;//Inputting the size of the array.
	cout<<endl;

	int arr[n];//arr array would store the input data given by the user.
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the value of element "<<i+1<<" : ";
		cin>>arr[i];//Inputting the values in the array.
	}

	/*temp1[i] would store the longest increasing subsequence from left to right if arr[i] was the last element of the 
	  subsequene.*/
	int temp1[n];
	for(int i=0;i<n;i++)
		temp1[i]=1;//Initializing all values of temp1 with 1.

	for(int i=1;i<n;i++)//Implementing the algorithm to find temp1[i].
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			temp1[i]=max(temp1[i],temp1[j]+1);
		}
	}

	/*temp2[i] would store the longest increasing subsequence from right to left if arr[i] was the last element of the 
	  subsequence*/
	int temp2[n];
	for(int i=0;i<n;i++)
		temp2[i]=1;//Initializing all values of temp2 with 1.

	for(int i=n-2;i>=0;i--)//Implementing the algorithm to find temp2[i].
	{
		for(int j=n-1;j>i;j--)
		{
			if(arr[i]>arr[j])
				temp2[i]=max(temp2[i],temp2[j]+1);
		}
	}

	int max=-1;//max would store the maximum length of the longest bitonic subsequence.
	for(int i=0;i<n;i++)//Implementing algorithm to find max.
	{
		if(max<temp1[i]+temp2[i]-1)
			max=temp1[i]+temp2[i]-1;
	}	

	cout<<"The longest Bitonic Subsequence is of length : "<<max<<endl;//Printing the longest length of such sequence.

	return 0;
}