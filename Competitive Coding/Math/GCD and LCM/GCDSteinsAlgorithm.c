//Program to calculate the GCD of two numbers by Stein's Algorithm and

#include<stdio.h>
#include<math.h>                        //For pow function


int gcdSteins(int m ,int n, int *k){

    //m and n are the integers.
    //k counts the number of common '2' factors

    //Base conditions
    if(m == n)
        return m;
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    //End of base conditions

    //To check if m is even
    if(~(m & 1) == 1){

        //if n is even
        if(~(n & 1) == 1){
            *k = *k + 1;
            return gcdSteins((m >> 1) , (n >> 1) , k);                   // m and n are divided by two. k is incremented
        }

        //if n is odd
            return gcdSteins((m >> 1) , n , k);                                  // m is divided by 2
    }

    //m is odd and n is even case
    if(~(n & 1) == 1)
        return gcdSteins(m ,(n >> 1) ,k);                                      // n is divided by 2

    //Both are odd case
    if(m > n)
        return gcdSteins(((m-n)>>1) , n , k);

    return gcdSteins(((n-m)>>1) , m , k);
}

//Driver Function
int main(){

    int m , n ,Gcd , k;
    //Test 1
    m = 120 , n = 210 , k = 0;
    Gcd = gcdSteins(m,n,&k);
    Gcd *= pow(2,k);
    printf("\nThe GCD of %d and %d is %d.", m , n , Gcd);

    //Test 2
    m = 2 , n = 6 , k = 0;
    Gcd = gcdSteins(m,n,&k);
    Gcd *= pow(2,k);
    printf("\nThe GCD of %d and %d is %d.\n\n", m , n , Gcd);

    return 0;
}
//End driver function
