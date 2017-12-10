#include<bits/stdc++.h>

using namespace std;

int main()
{
	int rod_length;
	cout<<"Enter the length of the rod : ";
	cin>>rod_length;//Inputting the length of the rod from user.
	cout<<endl;

	int price[rod_length];//price[i] stores the price of rod of length i+1.
	for(int i=0;i<rod_length;i++)
	{
		cout<<"Enter the price of rod of length "<<i+1<<" : ";
 		cin>>price[i];//Inputting the price of rod of length i+1 from user.
	}
	cout<<endl;
	
	/*Array to store the optimal values of subproblem.Eg: temp[2][3] would store the maximum selling price of rod of
	  length 3 with cuts of at max length 2 allowed i.e with cut lengths of 0 or 1 or 2 allowed.*/
 	int temp[rod_length+1][rod_length+1];

 	for(int i=0;i<rod_length+1;i++)//i denotes the maximum length of cutted rods.
 	{
 		for(int j=0;j<rod_length+1;j++)//j denotes the current lenght of the rod.
 		{
 			if(j==0)
 				temp[i][j]=0;/*setting the value 0 because j=0 means no rod hence no price for any case.*/	
 			else if(i==0)
 				temp[i][j]=price[j-1];/*if 0 cuts were allowed means we are selling the rod as a single piece 
							and hence setting the value from price array which contains the price of
							the rod as a single piece.*/
 			else if(i>j)
 				temp[i][j]=temp[i-1][j];/*length of the cutted rod greater than the length of original rod which is not possible and
							  thats why we are setting it with the optimal value of previous case. */
 			else
 				temp[i][j]=max(price[i-1]+temp[i][j-i],temp[i-1][j]);//Calculating the optimal value.
 		}
 	}

 	cout<<"The Maximum value that can be obtained is : "<<temp[rod_length][rod_length]<<endl;//Printing the final answer.

 	return 0;
}
