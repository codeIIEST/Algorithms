//Program to count the NUMBER OF 1's in the binary representation of a decimal number
#include<iostream>
using namespace std;

int main()
{
	int num=256;//Number to be checked whether is a power of 2 or not

	if (num && !(num & (num - 1)))//Checking the required condition as explained.
		cout<<num<<" is a Power of 2"<<endl;
	else 
		cout<<num<<" is not a Power of 2"<<endl;
}
