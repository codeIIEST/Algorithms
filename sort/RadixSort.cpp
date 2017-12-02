#include<iostream>
#include<cstring>
using namespace std;



/*
Use of Radix Sort :
Counting sort is a linear tine sorting algorithm that sort in O(n+k) time when elements are in range from 1 to k.

What if the elements are in range from 1 to n2?
We can’t use counting sort because counting sort will take O(n2) which is worse than comparison based sorting algorithms.
Can we sort such an array in linear time?
Radix Sort is the answer. The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
*/

/*Algo :
The Radix Sort Algorithm
1) Do following for each digit i where i varies from least significant digit to the most significant digit.
………….a) Sort input array using counting sort (or any stable sort) according to the i’th digit.
*/
/* Complexity Analysis :
 O(d*(n+b)) time where b is the base for representing numbers, for example, for decimal system, b is 10.
d is the no of digits = log2(n)
b is the base          = 10
Its more like O(18(n+10)) = O(N)

Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort?
If we have \log_2(n) bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more effectively.
Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.
*/
//----------------------------Find the largest elent
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
//-------------------------------------Counting Sort SubRoutine
void countingSort(int *a,int n,int exp){
    int output[n];
    int count[10];
    memset(count,0,sizeof count);
    int i;

    for(i=0;i<n;i++){
    count[(a[i]/exp)%10]++;
    }

    for(i=1;i<10;i++){
    count[i]+=count[i-1];
    }
    //Build the array
    for(i=n-1;i>=0;i--){
        output[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=output[i];

}

//------------------------------------------Radix Sort
void radixSort(int *a,int n){

int m = getMax(a,n);
for(int exp=1;m/exp > 0; exp=exp*10){
    countingSort(a,n,exp);
    }
}
//--------------------------------------Print
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main(){

    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a)/sizeof(int);
    radixSort(a, n);
    print(a, n);
}
