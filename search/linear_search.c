#include <stdio.h>
#include <stdlib.h>
int main()
{
   int *array, search, c, n_terms;
 
   printf("Enter the number of elements in array\n");
   scanf("%d",&n_terms);      // Total no of elements
 
   array = (int*)malloc(sizeof(int)*n_terms);
   printf("Enter %d integer(s)\n", n_terms);
 
   for (c = 0; c < n_terms; c++)
      scanf("%d", &array[c]);    //  Reading the elements
 
   printf("Enter the number to search\n");   // Target element to be searched
   scanf("%d", &search);
 
   for (c = 0; c < n_terms; c++)
   {
      if (array[c] == search)     /* if required element found */
      {
         printf("%d is present at location %d.\n", search, c+1);
         break;
      }
   }
   if (c == n_terms)
      printf("%d is not present in array.\n", search);   // Element not found
 
   return 0;
}
