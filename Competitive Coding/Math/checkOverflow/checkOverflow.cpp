// CPP program to check for integer
// overflow on multiplication
#include <iostream>
using namespace std;
// Function to check whether there is
// overflow in a * b or not. Ittreturns
// true if there is overflow.
bool isOverflow(long long a, long long b)
{
	// Check if either of them is zero
	if (a == 0 || b == 0) 
		return false;

	long long result = a * b;
	if (a == result / b)
		return false;
	else
		return true;
}

int main()
{
	long long a;
	long long b;
	scanf("%lld%lld",&a,&b);
	if (isOverflow(a, b))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
