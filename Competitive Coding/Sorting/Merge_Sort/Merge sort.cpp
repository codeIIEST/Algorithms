#include<iostream>
using namespace std;

//Function Declarations
void print_array(int arr[],int arr_size);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);

//Printing the array
void print_array(int arr[],int arr_size){
	for(int i=0;i<arr_size;i++){
		cout<<arr[i]<<" ";
	}
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
	int m,l,r;
	int arr[]={7,4,3,9,2,1,6,8,5,0}; //Creating an array of integers
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	//m=(l+r)+1/2;
	cout<<"Given array: ";
	print_array(arr,arr_size);
	cout<<"\n\nArray Size is: "<<arr_size<<endl;
	
	mergeSort(arr,0,arr_size-1);
	
	cout<<"\nAfter sorting the array: ";
	print_array(arr,arr_size);
	
	return 0;
}
