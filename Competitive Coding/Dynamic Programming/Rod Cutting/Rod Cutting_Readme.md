Rod-Cutting Problem :-

Algorithm Paradigm : Dynamic Programming

Time Complexity : Quadratic

Space Complexity : Quadratic

Problem-statement:
Given a rod of length n and an array of prices of rods of length less than or equal to n.Determine the maximum value that can be obtained by cutting the rod and selling the pieces.

Working:

Here price array stores the price of rod of different lengths.eg:price[3] stores the price of rod of length 4. 

Using the temp array we are building the solution using the best value of smaller cases(sub-problems).
temp[i][j] stores the maximum price  that can be obtained if we had rod of length j and at cuts of at max length i were allowed.

Using his technique we are bringing the time complexity down from exponential (as in case of brute force solution) to polynomial.



