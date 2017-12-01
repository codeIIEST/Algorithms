#include<stdio.h>
#include<stdlib.h>

int main() {
 
 int n_terms, *arr, item, i, j, mid, top, bottom;
 
 
 
 printf("Enter how many elements you want:\n");   // no of elements
 scanf("%d", &n_terms);
 arr = (int*)malloc(sizeof(int)*n_terms);
 printf("Enter the %d elements in ascending order\n", n_terms);    
 for (i = 0; i < n_terms; i++) {
    scanf("%d", &arr[i]);
 }
 
 printf("\nEnter the item to  search\n");   // Target element to be searched
 scanf("%d", &item);
 bottom = 1;
 top = n_terms;
 
 do {
  mid = bottom +  (top - bottom)/2 ; // same as (bottom + top / 2) but considers overflow condition when bottom + top might be larger than int 
  if (item < arr[mid])
   top = mid - 1;                            // Here we are dividing the array into two equal parts 
  else if (item > arr[mid])                   /* if target element > mid part of array , we do the search in the upper part of the array
                                            else search in the lower part */
   bottom = mid + 1;
 } while (item != arr[mid] && bottom <= top);
 
 if (item == arr[mid]) {
  printf("Binary search successfull!!\n");
  printf("%d found in position: %d\n", item, mid + 1);
 } else {
  printf("Search failed\n%d not found\n", item);
 }
 return 0;
}
