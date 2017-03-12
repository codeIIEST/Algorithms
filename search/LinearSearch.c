#include <stdio.h>
 
int main()
{
   int array[100], search, c, n;
 
   printf("Enter the number of elements in array\n");
   scanf("%d",&n);      // Total no of elements
 
   printf("Enter %d integer(s)\n", n);
 
   for (c = 0; c < n; c++)
      scanf("%d", &array[c]);    //  Reading the elements
 
   printf("Enter the number to search\n");   // Target element to be searched
   scanf("%d", &search);
 
   for (c = 0; c < n; c++)
   {
      if (array[c] == search)     /* if required element found */
      {
         printf("%d is present at location %d.\n", search, c+1);
         break;
      }
   }
   if (c == n)
      printf("%d is not present in array.\n", search);   // Element not found
 
   return 0;
}
