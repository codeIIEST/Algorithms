#include<stdio.h>
#include<limits.h>

int max(int a, int b)
 {
	 return (a > b)? a : b;
 }

int DPcutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }

   return val[n];
}

int main()
{
		int n;
		printf("Enter rod length\n");
		scanf("%d",&n);
		int arr[n],i;
		printf("Enter prices for lengths 1 to n\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
    printf("Maximum Obtainable Value is %d\n", DPcutRod(arr, n));
    getchar();
    return 0;
}
