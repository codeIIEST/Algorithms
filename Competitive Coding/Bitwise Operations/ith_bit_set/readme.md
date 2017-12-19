#Check whether the ith bit is set in a number using Bitwise Operations
 
Let’s say we have a number N, and to check whether it’s ith bit is set or not, we can AND it with the number 2^i . The binary form of 2^i contains only ith bit as set (or 1), else every bit is 0 there. When we will AND it with N, and if the ith bit of N is set, then it will return a non zero number (2^i to be specific), else 0 will be returned.

Using Left shift operator, we can write 2^i as 1 << i .

Example:
Let’s say N = 20 = {10100}2. Now let’s check if it’s 2nd bit is set or not(starting from 0). For that, we have to AND it with 2^2 = 1<<2 = {100}base 2 . 
{10100} & {100} = {100} = 2^2 = 4(non-zero number), which means it’s 2nd bit is set.



