
// BUBBLE SORT

#include <stdio.h>

void swap(int*,int*);

void bubblesort(int arr[], int size)
{
    int i, j, flag;
    for (i = 0;  i < size - 1; i++)     //  Function where the actual algorithm is implemented
    {
        flag=1;                         
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                flag=0;
                swap(&arr[j], &arr[j+1]);
            } 
        }
        if(flag==1)                     //   No change in vlaue of flag depicts that the array has been sorted
            break;
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
