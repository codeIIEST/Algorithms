#include <iostream>
using namespace std;

//--------------------------------------Heapify 
void max_heapify(int *a, int i, int n)
{
    int left, largest;
    largest = a[i];
    left = 2*i;
    while (left <= n)
    {
        if (left < n && a[left+1] > a[left])
            left = left+1;
        if (largest > a[left])
            break;
        else if (largest <= a[left])
        {
            a[left/2] = a[left];
            left = 2*left;
        }
    }
    a[left/2] = largest;
    return;
}

//-----------------------------------HeapSort
void heapsort(int *a, int n)
{
    int i, largest;
    for (i = n; i >= 2; i--)
    {
        largest = a[i];
        a[i] = a[1];
        a[1] = largest;
        max_heapify(a, 1, i - 1);
    }
}

//---------------------------------Build max Heap
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

int main()
{
    int n, i, x;
    cout<<"Enter no of elements of array\n";
    cin>>n;
    int a[20];
    for (i = 1; i <= n; i++)
    {
        cout<<"Enter element "<<(i)<<endl;
        cin>>a[i];
    }
    build_maxheap(a,n);
    heapsort(a, n);
    cout<<"\n\nSorted Array :\n";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
