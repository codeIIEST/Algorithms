// C++ Program to implement randomized quick sort with worst case time complexity O(nlogn) instead of O(n2) 

#include<iostream>    //std::cout
#include<algorithm>   //std::random_shuffle
#include<stdlib.h>    //std::rand
#define MAX 100
using namespace std;


//function to swap the 2 values
void swap( int *first , int *second )
{
    int temp ;
    temp = *first;
    *first = *second;
    *second = temp;

}
 
 
// Randomly selects a pivot and partitions the array . Uses Lamunto Algorithm for partition.
int partition( int arr[], int beg , int end )
{
  int pivot_index = beg + rand()%(end-beg+1);  // generates a random pivot between beg and end
  int pivot = arr[pivot_index];
  swap(&arr[end],&arr[pivot_index]);
  int small = beg - 1;
  int large ;
  for( large = beg ; large < end ; large++ )
  {
      if(arr[large]<pivot)
      {
          small++ ;
          swap(&arr[small],&arr[large]);
      }

  }
  swap(&arr[small+1],&arr[end]);
  return small+1;
}


//recursive quicksort function to sort the array
void quicksort( int arr[] , int first , int last )
{

    int pivot ;
    if(first<last)
    {
        pivot = partition(arr,first,last);

        //recursive calls to quicksort
        quicksort(arr,first,pivot-1);
        quicksort(arr,pivot+1,last);

    }

}


int main()
{

   int arr[MAX];
   int total_no ;

   //inputs the size of array
   cout<<"Enter no of elements you want to sort " ;
   cin>>total_no;

   //inputs the array
   cout<<"Enter the elements ";
   for ( int i = 0 ; i < total_no ; i++ )
   {
    cin>>arr[i];
   }

   //to implement randomised quick sort more efficiently we shuffle the array
   random_shuffle(&arr[0],&arr[total_no-1]);

   // calling quicksort
   quicksort(arr,0,total_no-1);

   //printing the sorted array
   for( int j = 0 ; j<total_no ; j++)
   {
    cout<<arr[j]<<" ";
   }

}

