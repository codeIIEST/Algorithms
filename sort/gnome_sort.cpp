
#include<iostream>
using namespace std;
 

void gnomeSort(int arr[], int n)
{
    int i = 0;
 
    while (i < n)
    {
        if (i == 0)
            i++;
        if (arr[i] >= arr[i-1])
            i++;
        else
        {
            swap(arr[i], arr[i-1]);
            i--;
        }
    }
    return;
}
 

void printArray(int arr[], int n)
{
   cout << "Sorted sequence after Gnome sort: ";
   for (int i=0; i < n; i++)
       cout << arr[i] << " ";
   cout << "\n";
}
 

int main()
{
    int arr[] = {2,53,1,-5};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    gnomeSort(arr, n);
    printArray(arr, n);
 
    return (0);
}
