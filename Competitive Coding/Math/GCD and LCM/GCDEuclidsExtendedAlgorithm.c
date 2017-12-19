//Program to calculate the GCD of two numbers by Extended Euclid's Algorithm and
//to find the integers x and y in the equation mx + ny = gcd(m,n)
//n is assumed to be following the following constariant: n >= m

#include<stdio.h>

//Function to caluclate the GCD of two numbers with euclid's extended Algorithm
int gcdExtended(int m, int n, int *x, int *y){

    //m and n are the integers
    //x and y are the integers in the equation mx + ny = gcd(m,n)
    //x1 and y1 are the intermediate x and y in the recursive calculate
    int x1 , y1 , gcd;
    if(m == 0){

        *x = 0;
        *y = 1;
        return n;
    }
    gcd = gcdExtended(n%m,m,&x1,&y1);
    *x = y1 - (n/m)*x1;
    *y = x1;
    return gcd;
}

//Driver Function
int main(){

    int m , n , gcd , x , y;
    //Test 1
    m = 74 , n = 120;
    gcd = gcdExtended(m,n,&x,&y);
    printf("\n The GCD is %d and x = %d , y = %d.", gcd , x , y);
    //Test 2
    m = 12 , n = 22;
    gcd = gcdExtended(m,n,&x,&y);
    printf("\n The GCD is %d and x = %d , y = %d.", gcd , x , y);

    return 0;
}
//Driver function ends
