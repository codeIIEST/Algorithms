Problem : To find the maximum subarray sum.

Language used : C++

Input : An integer array given by the user.

Output : A single integer denoting the maximum subarray sum.

Algorithm Paradigm : Dynamic Programming.

Time Complexity : Linear

Space Complexity : Constant

Working :- 

We are traversing the array and storing the sum of contiguous elements in sum variable.
As the value of sum reaches its maximum value that value is stored in max_so_far variable.
And as the value of sum becomes negative,we are setting the value of sum again to 0 as now its time to look for another subarray as the net sum of the elements of the previous subarray became negative. 

