#include <iostream>
using namespace std;

bool isOverflow(long long a, long long b)
{
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
