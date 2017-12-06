#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*link;
}*start=NULL;

void main()
{
    int choice=1;
    printf("Enter the element(s) of linked list:- ");
    do
    {
        create();
        printf("\nDo you wish to continue: If yes, press 1\n Else press 0\n");
        printf("Choice: ");
        scanf("%d",&choice);
    }
    while(choice==1);
        display();

  if(start==NULL)
    printf("LIST IS EMPTY");
  else
  {problem();
  display2();}

    }

    create()
    {
        struct node *temp,*ptr;

            temp=(struct node *)malloc(sizeof(struct node));
            temp->link=NULL;
            printf("\nEnter info: ");
            scanf("%d",&temp->info);

            if(start==NULL)
            {
                start=temp;
                start->link=start;
            }
            else
            {
                ptr=start;
                while(ptr->link!=start)
                   {
                      ptr=ptr->link;
                   }

                ptr->link=temp;
                temp->link=start;
            }
        }

    display()
    { struct node *ptr;

    if(start==NULL)
        printf("LIST IS EMPTY");

    else
    {
        ptr=start;
        printf("\n\nThe linked list is: ");
        while(ptr->link!=start)
        {
            printf("%d\t",ptr->info);
            ptr=ptr->link;
        }
        if(ptr->link==start)
           printf("%d\t",ptr->info);
    }

    }

    problem()
    {
        struct node *ptr,*temp,*pre;
        int i,n;

        printf("\n\nEnter the position to be deleted:-");
        scanf("%d",&n);

        temp=start;
        ptr=start->link;

        i=2;
        while(i<n)
        {
            temp=ptr;
            ptr=ptr->link;
            i++;
        }
        temp->link=ptr->link;
        free(ptr);
        ptr=temp->link;
        i=1;

        while(ptr->link!=ptr)
        {
        for(i=1;i<n;i++)
        {
//
                temp=ptr;
                ptr=ptr->link;
        }

        temp->link=ptr->link;
        free(ptr);
        ptr=temp->link;
    }
    }

    display2()
    {
        struct node *ptr;
        printf("\nThe number left is :- %d",ptr->info);
    }
