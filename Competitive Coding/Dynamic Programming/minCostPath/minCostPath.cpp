#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	/*
		We can easily observe that the optimum solution of the minimum
		cost at any row i is only dependent on the cost at row i-1 and
		the current row elements. Thus if we only store these two arrays
		of length c, We have reduced space from n*m to 2*m.
	*/

	int i, j, r, c;
  printf("Enter no of rows and no of cols\n");
	cin>>r>>c;     //take input of the rows and columns from user.
	int cost[c], dp[c];
	int x;
	/*
		Since for the first row the minimum cost is the only cost possible
		required to get there, we directly calculate it.
	*/
  printf("Enter a R X C array\n");

	for(i=0; i<c; i++){
		cin>>cost[i];
		if(i>0) cost[i] = cost[i] + cost[i-1];
	}
	/*
		For the subsequent rows, the optimised cost for each cell in the
		previous row has been stored in the array cost[] and the optimised
		cost for the present row is stored in the array dp[].
	*/
	for(i=1; i<r; i++){
		for(j=0; j<c; j++){
			cin>>x;
			if(j==0)
				dp[j] = cost[j] + x;
			else{
				dp[j] = x + min(dp[j-1], min(cost[j-1], cost[j]));
			}
		}
		/*
			After dp[] has been found entirely, we copy its elements to
			cost[] and continue the iteration.
		*/
		for(j=0; (j<c && i!=c-1); j++){
			cost[j] = dp[j];
		}
	}
  printf("The min cost path from 1,1 to r,c is\n");
	cout<<dp[c-1]<<"\n";
	return 0;
}
