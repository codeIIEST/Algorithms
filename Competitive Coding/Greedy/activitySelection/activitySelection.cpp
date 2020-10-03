#include<stdio.h>

void selection(int s[], int f[], int n)
{
    int i, j;
    i = 0;
    printf("%d ", i);

    for (j = 1; j < n; j++)
    {
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}

int main()
{
    int n;
    printf("Enter no of activities\n");
    scanf("%d",&n);
    int s[n],f[n],i;
    printf("Enter the start times of the activities\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
    }
    printf("Enter the finish times of the actvities\n");
    for(i=0;i<n;i++)
    {
      scanf("%d",&f[i]);
    }
    printf("Following activities are selected\n");
    selection(s, f, n);
    return 0;
}
