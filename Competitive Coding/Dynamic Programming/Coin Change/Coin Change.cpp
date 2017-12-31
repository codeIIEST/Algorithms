//Coin change problem using dynamic programming in C++.
#include<bits/stdc++.h>

using namespace std;

int main()
{
		int M;//Variable to store the number of different currency values.
		cout<<"Enter the number of denominations : ";
		cin>>M;//Inputting the number of different currency value from user.
		cout<<endl;

		int arr[M];//Array to store different currency values.
		for(int i=0;i<M;i++)
		{
			cout<<"Enter the value of denominaion "<<i+1<<" : ";
			cin>>arr[i];//Inputting the value of each currency from user.
		}
		cout<<endl;

		int N;//Variable to store the number of cents whose number of ways to make change is to be found.
		cout<<"Enter the number of cents : ";
		cin>>N;//Inputting the number of cents from user.
		cout<<endl;

		/*2D array to store the optimal value for sub-cases.*/
		int temp[M+1][N+1];

		for(int i=0;i<M+1;i++)//Implementing the algorithm.
		{
			for(int j=0;j<N+1;j++)
			{
				if(i==0 || j==0)
					temp[i][j]=0;
				else if(j<arr[i-1])
					temp[i][j]=temp[i-1][j];
				else if(j==arr[i-1])
					temp[i][j]=1+temp[i-1][j];
				else
					temp[i][j]=temp[i-1][j]+temp[i][j-arr[i-1]];
			}
		}

		cout<<"Number of ways to make change for "<<N<<" cent is "<<temp[M][N]<<endl;//Printing the final answer.
		
	return 0;
}