#include<iostream>
using namespace std;


//-------------------------------------------Heapify
void maxHeapify(int *a,int i,int n){
//Runs in O(logN) , floats down value at index i until a[i] becomes a max heap
int left = 2*i+1;
int right = 2*i+2;
int largest = i;

if(left<n&&a[left]>a[i])
    largest = left;
if(right<n&&a[right]>a[largest])
    largest = right;
if(largest!=i)
    {swap(a[i],a[largest]);
    maxHeapify(a,largest,n);
    }
}
//--------------------------------------Build max Heap
void buildMaxHeap(int *a,int n){
int i;
    for(i=n/2;i>=0;i--)
    {
    maxHeapify(a,i,n);
    }
}
//-----------------------------------HeapSort
void heapSort(int *a,int n){
buildMaxHeap(a,n);
for(int i=n-1;i>=0;i--){
    swap(a[i],a[0]);
    n--; //Decrease the heap Size
    maxHeapify(a,0,n);
    }
}

//----------------------------Print Function
void print(int *a,int n){
    for(int i=0;i<5;i++)
        cout<<a[i]<<" "<<endl;

}

int main(){

int a[]={5,1,2,0,6};
heapSort(a,5);
print(a,5);
return 0;
}
