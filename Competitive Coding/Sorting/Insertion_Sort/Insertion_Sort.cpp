#include<bits/stdc++.h>
using namespace std;

int main()
{
	int size, arr[50], i, j, temp;
	cout<<"Enter Array Size : ";
	cin>>size;
	cout<<"Enter Array Elements : ";
	for(i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	
	for(i=1; i<size; i++)
	{
		temp=arr[i];
		while((temp<arr[i-1]) && ((i-1)>=0))
		{
			arr[i]=arr[i-1];
			i=i-1;;
		}
		arr[i]=temp;
	}
	cout<<"Array after sorting : \n";
	for(i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
