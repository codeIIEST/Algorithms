Problem :-
=======
To find the longest Bitonic Subsequence(a bitonic subsequence is a sequence which strictly increases first then strictly decrases) in a given array of numbers.

Input :-
-----
The size of an array(n) and the contents of the array(arr).

Output :-
------
A single integer printing the maximum length of the bitonic subsequence present in the given array.

#### Language : `C++`

#### Algorithm Paradigm : `Dynamic Programming`

#### Time Complexity : `O(N^2)`

#### Space Complexity : `O(N)`

Working :-
-------
This problem is an application of the longest increasing subsequence problem also solved using dynamic programming.

For any `arr[i]` we are finding the longest increasing subsequence from left to right keeping the `arr[i]` the last element(lets call it `a`).Then we are finding the longest increasing subsequence from right to left keeping `arr[i]` the last element(lets call it `b`).Then we are finding `a+b-1` (subtracting `1` because `arr[i]` has been counted twice) which gives us the length of the bitonic subsequence with `arr[i]` as its peak element.
We are repeating above process for all the elements in the array and finding the max value of all `a+b-1` which gives us the length of the longest bitonic subsequence.

By using dynamic programming we are bringing the time complexity down from exponential(as in case of brute force solution) to polynomial.