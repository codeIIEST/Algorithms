//Program to calculate the GCD of a number by Euclids algorithm, and then find its LCM

#include<stdio.h>

//Function to calculate the GCD
//It is assumed that n >= m
int gcd(int m, int n){

    if(m == 0)
        return n;
    else
        return gcd((n%m) , m);
}

//Function to calculate LCM
int lcm(int m, int n, int gcdOfmn){

    int lcm = (m * n) / gcdOfmn;
    return lcm;
}

//Driver Function
int main(){

    int m , n ,Gcd;
    //Test 1
    m = 120 , n = 210;
    Gcd = gcd(m,n);
    printf("\nThe GCD and LCM of %d and %d are %d and %d.", m , n , Gcd , lcm(m,n,Gcd));
    //Test 2
    m = 12 , n = 66;
    Gcd = gcd(m,n);
    printf("\n\nThe GCD and LCM of %d and %d are %d and %d.\n\n", m , n , Gcd , lcm(m,n,Gcd));
    return 0;
}
//End driver function
