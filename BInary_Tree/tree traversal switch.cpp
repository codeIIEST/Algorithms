#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* newnode(int data)
{
	struct node* node =(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void Inorder(struct node* root)
{
	if(root==NULL)
	return ;
	
	Inorder(root->left);
	printf("%d\t",root->data);
	Inorder(root->right);
}
void Preorder(struct node* root)
{
	if(root==NULL)
	return ;
	
	printf("%d\t",root->data);
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(struct node* root)
{
	if(root==NULL)
	return ;
	
	Postorder(root->left);
	Postorder(root->right);
	printf("%d\t",root->data);
	
}

int main()
{  // struct node* root=NULL;
 struct node *root  = newnode(1);
     root->left             = newnode(2);
     root->right           = newnode(3);
     root->left->left     = newnode(4);
     root->left->right   = newnode(5);
	int choice;
	while(1)
	{
		printf("\n1.INORDER\n");
		printf("2.PREORDER\n");
		printf("3.POSTORDER\n");
		printf("4.EXIT\n");
		printf("enter the choice");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				Inorder(root);
				break;
			case 2:
				Preorder(root);
				break;
			case 3:
				Postorder(root);
				break;
			case 4:
				exit(1);
				break;
				
		}
	}
return 0;	
}
