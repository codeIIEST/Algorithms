//Code to find the maximum subarray sum using dynamin programming in c++.
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the size of the array : ";//Inputting the size of the array.
	cin>>n;
	cout<<endl;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the value of element "<<i+1<<" : ";
		cin>>arr[i];//Inputting the values in the array.
	} 

	int max_so_far=-99999;//It will store the maximum subarray sum.
	int sum=0;//It will store the sum of the different subarrays.

	for(int i=0;i<n;i++)//Implementing the kadane's Algorithm.
	{
		sum+=arr[i];
		if(sum>max_so_far)
			max_so_far=sum;
		if(sum<0)
			sum=0;
	}

	cout<<"The maximum subarray sum is : "<<max_so_far<<endl;//Printing the answer i.e the maximum subarray sum.

	return 0;
}