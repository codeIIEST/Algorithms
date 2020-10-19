/*Given a number say(N).The task is to perform the following steps on N:-

1:- First find the new number(say M) after reversing the digits of N.

2:-Find the absolute difference between M and N , say(K).

3:-Sum the digits of K and print it.

INPUT:- 32347654

N=32347654

M=45674323

Difference:- 13333331

OUTPUT = 20

Approach:-

First divide the string of number N into two equal parts(One starts from index 0 and other from last till middle) 
and then just simply find the absolute difference between the digits of two strings. 
*/
#include <iostream>
#include<cmath>
using namespace std;
int main() {
	string n="24817",numb1="",numb2="";
	float length_of_number=n.length();
	for(int i=0;i<ceil(length_of_number/2);i++) numb1+=n[i];
	//numb1=248
	for(int i=(n.length()-1);i>=floor(length_of_number/2);i--) numb2+=n[i];
	//numb2=718
	int sum=0;
	for(int i=0;i<numb1.length();i++) sum+=abs(numb1[i]-numb2[i]);
	cout<< (2*sum) <<endl;
	return 0;
}
