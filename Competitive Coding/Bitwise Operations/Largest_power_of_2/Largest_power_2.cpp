#include <iostream>
using namespace std;
 
int main() {
   long N;
    cin>>N;
   largest_power(N);}
void largest_power(long N)
    { 
        //changing all right side bits to 1.
        N = N| (N>>1);
        N = N| (N>>2);
        N = N| (N>>4);
        N = N| (N>>8);


    //as now the number is 2 * x-1, where x is required answer, so adding 1 and dividing it by
     2. 
                printf((N+1)>>1;

    }