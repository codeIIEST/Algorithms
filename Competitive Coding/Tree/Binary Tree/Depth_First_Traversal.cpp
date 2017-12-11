/*C++ programme for Depth First Traversal(Inorder, Preorder and Postorder) Traversal of a Binary Tree
 Approach- Recursive*/

#include<iostream>
using namespace std;

/*Creating the structure of binary tree node having data amd pointers to left 
  and right child*/ 
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

};
//Function Prototypes
Node* newnode(int);
void InorderTraversal(Node*);
void PostorderTraversal(Node*);
void PreorderTraversal(Node*);
int main()
{
	Node* root=newnode(1);//Creating the tree
	root->left=newnode(3);
	root->right=newnode(5);
	root->left->left=newnode(6);
	root->right->right=newnode(4);
	root->left->right=newnode(12);
	
	cout<<"The Inorder Traversal of the tree gives::"<<endl;
	InorderTraversal(root);

	cout<<"\nThe Preorder Traversal of the tree gives::"<<endl;
	PreorderTraversal(root);

	cout<<"\nThe Postorder Traversal of the tree gives::"<<endl;
	PostorderTraversal(root);

}

//Function to allocates a new node, and initiales the left and right child with NULL
Node* newnode(int value)
{
 	Node* temp=(Node*)malloc(sizeof(Node));
 	temp->data=value;
 	temp->left=NULL;
 	temp->right=NULL;
 	return temp;

}

void InorderTraversal(Node* root)//Inorder Traversal: Left-Root-Right
{
	if(root==NULL)
		return;
	InorderTraversal(root->left);
	cout<<root->data<<" ";
	InorderTraversal(root->right);
}

void PreorderTraversal(Node* root)//Preorder Traversal: Root-Left-Right
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	PreorderTraversal(root->left);
	PreorderTraversal(root->right);
}

void PostorderTraversal(Node* root)//Postorder Traversal: Left-Right-Root
{
	if(root==NULL)
		return;
	PostorderTraversal(root->left);
	PostorderTraversal(root->right);
	cout<<root->data<<" ";
}

