//Program to count the no of 1's  in the binary representation of a given decimal number using Bitwise Operations.
#include<iostream>
using namespace std;

int main()
{
	int x=4;
	int count=0;//Variable to store the number of 1's in the decimal representation of x

	while(x)
	{
		x=x&(x-1);
		count++;
	}

	cout<<"The number of 1's in the decimal representation of "<<x<<"is "<<count;
}
