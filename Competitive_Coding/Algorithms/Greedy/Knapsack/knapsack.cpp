// This C++ program solves the 0-1 knapsack problem. A very famous Dynamic Programming problem.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll knapsack(ll V[], ll W[], ll n, ll maxWeight)
{
	ll K[n + 1][maxWeight + 1]; // Declaring the table for dynamic programming.
	for(ll i = 0; i <= n; i++)
	{
		for(ll j = 0; j <= maxWeight; j++)
		{
			if(i == 0 || j == 0)
				K[i][j] = 0; //Covering the base cases.

			else if(W[i - 1] <= j)// If the weight of the element is less than the capacity.
				K[i][j] = max(V[i - 1] + K[i - 1][j - W[i - 1]], K[i - 1][j]);// Then take the maximum of the value of this element or the leave this element.

			else
				K[i][j] = K[i - 1][j]; // If the weight of the element is more than the capacity, then leave this element.
		}
	}
	return K[n][maxWeight];
}

int main()
{
	ll n;
	cout << "Enter the value of n (The number of elements)." << endl;
	cin >> n;
	ll V[n], W[n];
	cout << "Enter " << n << " space separated integers denoting the values." << endl;
	for(ll i = 0; i < n; i++)
		cin >> V[i];
	cout << "Enter " << n << " space separated integers denoting the weights." << endl;
	for(ll i = 0; i < n; i++)
		cin >> W[i];
	ll maxWeight;
	cout << "Enter the value of the capacity of the knapsack" << endl;
	cin >> maxWeight;
	cout << "The maximum total value obtained with the following knapsack" << endl;
	cout << knapsack(V, W, n, maxWeight) << endl;
	return 0;
}
