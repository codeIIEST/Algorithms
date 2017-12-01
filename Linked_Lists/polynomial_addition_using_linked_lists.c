#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

typedef struct Node{
	int coeff;
	int power;
	Node* next;
}ll;
void  create_poly(int x,int y, ll** poly)
{
   ll* temp=*poly;
   if(temp==NULL)
   {
   	ll* new_node=(ll*)(malloc(sizeof(ll)));
   	new_node->coeff=x;
   	new_node->power=y;
   	new_node->next=NULL;
   	*poly=new_node;
   }
   else
   {
   	ll* new_node=(ll*)(malloc(sizeof(ll)));
   	new_node->coeff=x;
   	new_node->power=y;
   	new_node->next=temp;
   	*poly=new_node;

   }
   }

 void show_poly(ll* temp)
 {
 	while(temp!=NULL)
 	{   if(temp->next==NULL)
 		printf("%dx^%d",temp->coeff,temp->power);
 		else
 			printf("%dx^%d+ ",temp->coeff,temp->power);
 		temp=temp->next;
 	}
 }

 void add_poly(ll* poly1,ll* poly2,ll**  poly)
 {  
   
   ll* temp=(ll*)(malloc(sizeof(ll)));
   temp->next=NULL;
   *poly=temp;
   while(poly1&& poly2)
    {
    if(poly1->power>poly2->power)
     {
    temp->coeff=poly1->coeff;
	temp->power=poly1->power;
	poly1=poly1->next;
     }
    else if(poly1->power<poly2->power)
     {
	temp->coeff=poly2->coeff;
	temp->power=poly2->power;
	poly2=poly2->next;
     }
    else //if(poly1->power==poly2->power)
      {
      	temp->coeff=poly1->coeff+poly2->coeff;
	    temp->power=poly2->power;
	    poly2=poly2->next;
	    poly1=poly1->next;
       }
     if(poly1&&poly2){temp->next=(ll*)(malloc(sizeof(ll)));
     temp=temp->next;
     temp->next=NULL; }
}
 

 }

int main()
{
  ll* poly1=NULL;
  ll* poly2=NULL;
  ll* poly=NULL;
  //Creating the first polynomial
  create_poly(4,0,&poly1);
  create_poly(3,1,&poly1);
  create_poly(5,2,&poly1);
  create_poly(9,0,&poly2);
  create_poly(5,1,&poly2);
  create_poly(8,3,&poly2);
  show_poly(poly1);
  printf("\n");  show_poly(poly2);
  printf("\n"); 
  add_poly(poly1,poly2,&poly);
  show_poly(poly);



}
