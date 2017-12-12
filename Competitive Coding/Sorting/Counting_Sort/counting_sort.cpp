// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255
 

void countSort(char arr[])
{
    
    char output[strlen(arr)];
 
    // Create a count array to store count of inidividul
  
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
 
    for(i = 0; arr[i]; ++i)
        ++count[arr[i]];
 
     for (i = 1; i <= RANGE; ++i)
        count[i] += count[i-1];
 
    // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }
 
    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}
 

int main()
{
    char arr[] = "chirayu";//"jain";
 
    countSort(arr);
 
    printf("Sorted character array is %s", arr);
    return 0;
}
