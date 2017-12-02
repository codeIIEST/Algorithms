// This C++ program finds the presence of a pattern in a text. Using the Rabin-Karp algorithm.
// This program first calculates the hash value of the pattern and matches them with the part of the text.
// If the hash value matches then only it matches the corresponding characters. 
// This algorithm basically uses a rolling hash function. 
// @author heisenberg
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void rabinKarp(string pattern, string text)
{
	ll prime = 101; // Take any prime number. Preferably in this range only.
	ll pLen = pattern.length();// Length of the pattern.
	ll tLen = text.length();// Length of the text.
	const ll noOfChars = 256;// No of the characters.
	ll hashP = 0;// Variable to store the hash value for the pattern.
	ll hashT = 0;// Variable to store the hash value of the part of the text.
	ll h = 1; // Variable to store the multiplier of the Most Significant Bit.
	bool indi = 0; // Just another indicator.
	//Calculating the value of h
	for(ll i = 0; i < pLen - 1; i++)
		h = (h * noOfChars) % prime;// Equivalent to calling pow(noOfChars, plen - 1)

	//Calculating the value of the hash for the pattern and the first pLen characters of the text.
	for(ll i = 0; i < pLen; i++)
	{
		hashP = (hashP * noOfChars + pattern[i]) % prime;
		hashT = (hashT * noOfChars + text[i]) % prime; 
	}
	// Iterating over the rest of the text and finding the matchings.
	for(ll i = 0; i <= tLen - pLen; i++)
	{
		bool flag = 0; // Just an indicator.
		if(hashP == hashT) // If the hash value match
		{
			for(ll j = 0; j < pLen; j++) //Then match the characters.
			{
				if(text[i + j] != pattern[j]) // If any of the characters dont match then break.
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				indi = 1; // Pattern found atleast once.
				cout << "Pattern found at index " << i << endl; 
			}
		}
		//Calculating the value of hash for the next substring of the text.
		hashT = (noOfChars * (hashT - (text[i] * h)) + text[i + pLen]) % prime; // Removing the last element out of the window and adding the last element.
		if(hashT < 0)// If the value of the hash becomes negative then
		{
			hashT += prime;
		}
	}
	if(indi == 0)
		cout << "The pattern is not in the text." << endl;
}


int main()
{
	string text, pattern;
	cout << "Enter the pattern to be searched" << endl;
	getline(cin, pattern);
	cout << "Enter the text in which the pattern is to be searched" << endl;
	getline(cin, text);
	rabinKarp(pattern, text);
	return 0;
}
