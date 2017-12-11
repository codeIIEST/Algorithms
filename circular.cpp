// c program to explain about the circular linked list concept 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL;
    
struct node *create(struct node*);
struct node *display(struct node*);
struct node *insertbeg(struct node*);
struct node *delbeg(struct node*);
struct node *insertend(struct node*);
struct node *delend(struct node*);


int main()
{
    int op;
    do
    {
    printf("enter 1. create\n enter 2. dispaly\n enter 3. insert at beg \n 4. del beg \n 5. insert at end \n 6. delend\n 7. exit\n");
    printf("enter the choice\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1: head=create(head);
            printf("circular linked list created\n");
            break;
        case 2: head=display(head);
            break;
        case 3: head=insertbeg(head);
            break;
        case 4: head=delbeg(head);
            break;
        case 5: head=insertend(head);
            break;
        case 6: head=delend(head);
            break;
        case 7: printf("exit choice\n");
            exit(1);
            break;
    }
    }while(op!=7);
}



struct node *create(struct node *head)
{
    struct node *newnode,*temp;
    int num;
    printf("enter -1 to end\n");
    printf("enter the data\n");
    scanf("%d",&num);
    while(num!=-1)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
    newnode->next=newnode;
    head=newnode;    
    }
    else
    {
    temp=head;
    while(temp->next!=head)
    temp=temp->next;
    temp->next=newnode;
    newnode->next=head;
    }
    printf("enter the data");
    scanf("%d",&num);
    }
    return head;
    }



struct node *display(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp->next!=head)
    {
    printf("\t %d",temp->data);
    temp=temp->next;
    }
    printf("\t %d\t",temp->data);
    return head; 
}



struct node *insertbeg(struct node *head)
{
    struct node *newnode,*temp;
    int num;
    printf("enter the data");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    temp=head;
    while(temp->next!=head)
    temp=temp->next;
    temp->next=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}





struct node *delbeg(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp->next!=head)
    temp=temp->next;
    temp->next=head->next;
    free(head);
    head=temp->next;
    return head;
}


struct node *delend(struct node *head)
{

    struct node *temp,*prev;
    temp=head;
    while(temp->next!=head)
    {
    prev=temp;
    temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}


struct node *insertend(struct node *head)
{
    struct node *newnode,*temp;
    int num;
    printf("enter the data");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    temp=head;
    while(temp->next!=head)
    temp=temp->next;
    temp->next=newnode;
    newnode->next=head;
    return head;
}
