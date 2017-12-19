//Program to find the prime factorization of a number in O(n^1/2) time

#include<stdio.h>
#include<math.h>

//Function to print prime factors of an integer n
void primeFactorization(int n){

    printf("\n\nThe prime factors of %d are: ", n);

    //To print factor as 2 until the number is odd
    while(n % 2 == 0){

        printf("2 ");
        n = n / 2;                                          //Dividing number by 2
    }

    //The number would be odd after exiting loop
    //Factors will be checked from i = 3 to root n, increasing i by 2 every loop, as all even numbers are taken acre of
    int i = 3 , sqrtN = sqrt(n);
    while(i<=sqrtN){

        //If i is a prime factor of n
        while(n%i==0){

            printf("%d ", i);
            n = n / i;
        }

        i = i + 2;
    }

    //If n > 2 after these steps, this tells us that n is aprime numbers
    if(n > 2){

        printf("%d " , n);
    }
    printf("\n\n");
}

//Driver function
void main(){

    printf("\n\n\tPRIME FACTORIZATION");
    printf("\n\nEnter number: ");
    int n;
    scanf("%d" , &n);
    primeFactorization(n);
}
//Main ends
