#include<bits/stdc++.h>

using namespace std;

int main()
{
	int rod_length;
	cout<<"Enter the length of the rod : ";
	cin>>rod_length;
	cout<<endl;

	int price[rod_length];//price[i] stores the price of rod of length i+1.
	for(int i=0;i<rod_length;i++)
	{
			cout<<"Enter the price of rod of length "<<i+1<<" : ";
 			cin>>price[i];
	}
	cout<<endl;
	
 	int temp[rod_length+1][rod_length+1];

 	for(int i=0;i<rod_length+1;i++)
 	{
 		for(int j=0;j<rod_length+1;j++)
 		{
 			if(j==0)
 				temp[i][j]=0;
 			else if(i==0 && j!=0)
 				temp[i][j]=price[i-1];
 			else if(i>j)
 				temp[i][j]=temp[i-1][j];
 			else
 				temp[i][j]=max(price[i-1]+temp[i][j-i],temp[i-1][j]);
 		}
 	}

 	cout<<"The Maximum value that can be obtained is : "<<temp[rod_length][rod_length]<<endl;

 	return 0;
}
