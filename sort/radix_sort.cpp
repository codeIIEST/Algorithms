#include<iostream>
using namespace std;
 
//max value in the array
int max(int arr[], int n)
{
    int a = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > a)
            a = arr[i];
    return a;
}
 
void countSort(int arr[], int n, int exp)
{
    int out[n]; 
    int i, count[10] = {0};
 
   
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
   
    for (i = n - 1; i >= 0; i--)
    {
        out[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    
    for (i = 0; i < n; i++)
        arr[i] = out[i];
}
 

void radixsort(int arr[], int n)
{
    
    int m = max(arr, n);
 
    
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    print(arr, n);
    return 0;
}