/*C programme for Level Order Traversal of a Binary Search Tree
  Approach- Recursive*/

#include<stdio.h>
#include<stdlib.h>
/*Creating the structure of binary tree node having data amd pointers to left 
  and right child*/ 
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

}T;
//Function Prototypes
T* newnode(int);
void LevelOrder(T*);
T* printGivenLevel(T*,int);
int height(T*);

int main()
{
	T* root=newnode(1);//Creating the tree
	root->left=newnode(3);
	root->right=newnode(5);
	root->left->left=newnode(6);
	root->right->right=newnode(4);
	root->left->right=newnode(12);
	LevelOrder(root);

}
//Function to allocates a new node, and initiales the left and right child with NULL
T* newnode(int value)
{
 	T* temp=(T*)malloc(sizeof(T));
 	temp->data=value;
 	temp->left=NULL;
 	temp->right=NULL;
 	return temp;

}
//Function that drives the level order traversal of the tree
void LevelOrder(T* root)
{
	int level;
	for(level=1;level<=height(root);level++)
		{printGivenLevel(root,level);}
}
/*Computes the height of the tree, which is the length of path from the root to
  to the deepest leaf node*/
int height(T* root)
{
	if(root==NULL)
			return 0;
	int lh=height(root->left);
	int rh=height(root->right);

	return lh>rh?lh+1:rh+1;
}

//Prints the nodes in each level of the tree
T* printGivenLevel(T* root,int level)
{
	if(root==NULL)return NULL;
	if(level==1)printf("%d ",root->data);
	else{
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);

	}
}
