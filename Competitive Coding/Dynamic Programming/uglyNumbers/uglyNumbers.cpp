#include<bits/stdc++.h>
using namespace std;
int main()
{
	printf("Enter no of test cases\n");
	int t; cin >> t;
	int i2, i3, i5;
	i2 = i3 = i5 = 0;
	int ugly[500];// To store ugly numbers
	ugly[0] = 1;
	for (int i = 1; i < 500; ++i) {
		ugly[i] = min(ugly[i2]*2, min(ugly[i3]*3, ugly[i5]*5));//get minimum of possible solutions
		ugly[i] != ugly[i2]*2 ? : i2++;		//      next_mulitple_of_2 = ugly[i2]*2;
		ugly[i] != ugly[i3]*3? : i3++;		//      next_mulitple_of_3 = ugly[i3]*3
		ugly[i] != ugly[i5]*5 ? : i5++;   //      next_mulitple_of_5 = ugly[i5]*5;
	}
	int n;
	while(t--) {
		printf("Enter 'n' for the nth ugly number\n");
		cin >> n;
		cout << ugly[n-1] << endl;
	}
	return 0;
}
