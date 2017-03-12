#include<stdio.h>
int main() {
 
 int n, a[30], item, i, j, mid, top, bottom;
 
 
 printf("Enter how many elements you want:\n");   // no of elements
 scanf("%d", &n);
 printf("Enter the %d elements in ascending order\n", n);    
 for (i = 0; i < n; i++) {
  scanf("%d", &a[i]);
 }
 
 printf("\nEnter the item to  search\n");   // Target element to be searched
 scanf("%d", &item);
 bottom = 1;
 top = n;
 
 do {
  mid = (bottom + top) / 2;
  if (item < a[mid])
   top = mid - 1;                            // Here we are dividing the array into two equal parts 
  else if (item > a[mid])                   /* if target element > mid part of array , we do the search in the upper part of the array
                                            else search in the lower part */
   bottom = mid + 1;
 } while (item != a[mid] && bottom <= top);
 
 if (item == a[mid]) {
  printf("Binary search successfull!!\n");
  printf("\n %d found in position: %d\n", item, mid + 1);
 } else {
  printf("\n  Search failed\n %d not found\n", item);
 }
 return 0;
}
