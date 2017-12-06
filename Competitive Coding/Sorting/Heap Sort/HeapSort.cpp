#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b,c) for(i=a;i<b;i+=c)
#define repp(i,a,b,c) for(i=a;i>b;i+=c)

//--------------------------------------Heapify 
void max_heapify(int *a, int i, int n)
{
    int l=2*i+1;
     int r=2*i+2;
     int largest=0;
     if(l<=n and a[l]>a[i])
     	 largest=l;
     else
         largest=i;
     if(r<=n and a[r]>a[largest])
         largest=r;
     if(largest!=i)
        {
        	swap(a[largest],a[i]);
        	max_heapify(a,largest,n);
        }
}
//---------------------------------Build max Heap
void build_maxheap(int *a, int n)
{
	int i;
     repp(i,n/2,-1,-1)
    {
    	max_heapify(a,i,n);
    }
}

//-----------------------------------HeapSort
void heapsort(int *a, int n)
{
	 int i;
    build_maxheap(a,n);
    repp(i,n,-1,-1)
       {
       	   swap(a[0],a[i]);
       	   n--;
       	   max_heapify(a,0,n);
       }
}

int main()
{
    int n, i, x;
    cout<<"Enter no of elements of array\n";
    cin>>n;
    
    //Dynamic Memory Allocation
    int *dynamic;
    dynamic = new int[n];
	
	//Input Of Elements
	cout<<"Enter the elements of array :\n";
    rep(i,0,n,1)
       cin>>dynamic[i];
    
    heapsort(dynamic,n-1);  
    //Sorted Array using heap sort
    cout<< "Sorted Sequence is : " ;
	
	rep(i,0,n,1)
      cout<< dynamic[i]<<"\t";
    delete []dynamic;
}