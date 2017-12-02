#include<iostream>
#include<cstring>
using namespace std;

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
