This is the code to build suffix array for any given string input.

Suffix Array:-
A suffix array for a given string is basically a sorted array of all suffixes of a string.

For example:-

Given the string is "banana"

The suffixes are:-

0 banana			5 a
1 anana          sorted		3 ana
2 nana       -------------->	1 anana
3 ana	      alpabetically	0 banana
4 na				4 na 
5 a				2 nana

So, the suffix array for the string "banana" will be [5,3,1,0,4,2]

Application of suffix array:-

Suffix array is an extremely useful data structure, it can be used for a wide range of problems. Following are some famous problems where Suffix array can be used.
1) Pattern Searching
2) Finding the longest repeated substring
3) Finding the longest common substring
4) Finding the longest palindrome in a string
