#Selection Sort

#include<stdio.h>
int main(){

  int s,i,j,temp,a[20];

  printf("Enter total elements: ");  // total no of elements
  scanf("%d",&s);

  printf("Enter %d elements: ",s);  // the elements
  for(i=0;i<s;i++)
      scanf("%d",&a[i]);

  for(i=0;i<s;i++){
      for(j=i+1;j<s;j++){
           if(a[i]>a[j]){
               temp=a[i];    // Compare between 2 consecutive elements and swap them if they are not in ascending order
              a[i]=a[j];
              a[j]=temp;
           }
      }
  }

  printf("After sorting is: ");
  for(i=0;i<s;i++)            //  Print the sorted array
      printf(" %d",a[i]);

  return 0;
}
