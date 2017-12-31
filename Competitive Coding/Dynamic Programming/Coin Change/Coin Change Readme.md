Problem :-
===
Given a value N and the values of different denomination,find the number of ways to make changes for N cents,if we have infinite supply of all denominations.

Input:-
---
Size of an array and all the values in the array and the number of cents.

Output :-
---
An integer that denotes the  number of ways to make change.

#### Language : `C++`

#### Algorithm Paradigm : `Dynamic Programming`

#### Time Complexity :  `O(N*M)`

#### Space Complexity : `O(N*M)`

Working :-
---
An arr array stores the different currency values.
Another array temp stores the best values for sub-problems.For eg: `temp[3][4]` stores the optimal value for the number of ways
to make change if the number of cents(N) were 4 and we only had `arr[0]`,`arr[1]` and `arr[2]` as the different values of currency.

By using dynamic programming we are bringing the time complexity down from exponentional(in case of brute force solution)
to polynomial.
