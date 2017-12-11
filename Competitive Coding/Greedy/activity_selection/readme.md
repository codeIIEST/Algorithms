PROBLEM STATEMENT:
Given n activities with their initial and final time, you have to select maximum number of activities which can be done by a person, provided he can only perform single activity at a time.

EXAMPLE:
let us suppose the following activities are given with their start and end time :
   
   start time     end time 
1.    5             12
2.    4             10
3.    3             15
4.    13            20
5.    20            25

In the above example the person can perform atmost 3 activities i.e. (5,12),(13,20),(20,25) or (4,10),(13,20) and (20,25).
This problem can be solved best by using Greedy Approach.

GREEDY SOLUTION:
The activities can be sorted according to their finish time(if the finish time of two or more activities are same then sort according to their start time), Then pick up the first activity and for the rest of the activities choose the one with the start time greater than or equal to the activity chosen before. Do the same steps until all the activities are checked out.

In the above example, The activities can be sorted in the following manner:
    start time     finish time
1.    4                10
2.    5                12
3.    3                15
4.    13               20
5.    20               25
 
Therefore three activities can be chosen now namely (4,10) (13,20) and (20,25).

This algorithm will take O(nlogn) time if the activities are not sorted otherwise it will take O(n) time.

            


