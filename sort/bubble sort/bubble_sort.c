
// BUBBLE SORT

#include <stdio.h>

void swap(int*,int*);

void bubblesort(int arr[], int size)
{
    int i, j;
    for (i = 0;  i < size - 1; i++)     //  Function where the actual algorithm is implemented
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
 
        }
    }
}
void swap(int *a, int *b)
{
    int temp;                         // Function for swapping two variables
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int array[100], i, size;
    printf("How many numbers you want to sort:  ");  // Enter the numbers to sort
    
    scanf("%d", &size);
    
    printf("\nEnter %d numbers : ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &array[i]);
    bubblesort(array, size);
    printf("\nSorted array is ");
 
    for (i = 0; i < size; i++)
        printf(" %d ", array[i]);
    printf(" ");
    return 0;
 
}
