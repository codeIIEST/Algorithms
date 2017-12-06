#include<stdio.h>
#define baseyear 2000

void main()
{
	short int date;
	short int temp,retrieve;


	printf("Enter Date:\n");
	scanf("%d",&temp);
	date=temp;

	printf("Enter Month:\n");
	scanf("%d",&temp);
	date=date|(temp<<5);

	/*printf("%d\n",date);
    printf("%d %d",temp,retrieve);*/

	printf("Enter Year:\n");
	scanf("%d",&temp);
	date=date|(temp-baseyear)<<9;

	printf("The total date information stored in 2 bytes has been encoded as follows: %d\n",date);


	retrieve=(date<<11);
	retrieve=retrieve>>11;
	if(retrieve<0)
    printf("The date is : %d\n",32+retrieve);
    else
    printf("The date is : %d\n",retrieve);


    retrieve=date<<7;
    retrieve=retrieve>>12;
    if(retrieve<0)
    printf("The month is : %d\n",16+retrieve);
    else
    printf("The month is : %d\n",retrieve);


    retrieve=date>>9;
    if(retrieve<0)
    printf("The year is : %d\n",128+retrieve+baseyear);
    else
    printf("The year is : %d\n",retrieve+baseyear);

}
