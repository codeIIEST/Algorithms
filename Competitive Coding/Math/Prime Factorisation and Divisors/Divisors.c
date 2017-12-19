//Program to find the divisors of an integer n in O(root n) time

#include<stdio.h>
#include<math.h>

// Function to print the divisors of integer n
void printDivisors(int n){

    printf("\n\nThe divisors of %d are: ", n);
    //Iterates from i=1 to root n and print divisors as i and n/i at one go
    for (int i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                printf("%d ", i);

            else // Otherwise print both
                printf("%d %d ", i, n/i);
        }
    }
    printf("\n\n");
}

//Driver Function
void main()
{
    printf("\n\n\tDIVISOR PROGRAM");
    int n;
    printf("\n\nEnter the integer: ");
    scanf("%d" , &n);
    printDivisors(n);
}
