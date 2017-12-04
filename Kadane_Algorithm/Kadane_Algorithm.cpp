//C++ code to find the maximum subarray sum using Kadane's Algorithm in linear time.
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
//Inputting the number of elements in the array.
	cout<<"Enter the number of elements in the array : ";
	cin>>n;
	cout<<endl;

	int arr[n];

//Inputting the values in array.
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the value of element "<<i+1<<" : ";
		cin>>arr[i];
	}

	int sum=0;//will store the sum of the elements in the array.
	int max_so_far=-99999;//Variable to store maximum value of subarray sum i.e our answer.


	for(int i=0;i<n;i++)//implementing Kadane's Algorithm.
	{
		sum+=arr[i];
		if(sum>max_so_far)
			max_so_far=sum;
		if(sum<0)
			sum=0;
	}

	cout<<"The maximum subarray sum is "<<max_so_far<<endl;

	return 0;
}