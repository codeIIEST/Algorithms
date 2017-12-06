//Check tree is BST or not using INORDER traversal//
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *left,*right;
};
 bool BST(struct node* root)
  {
    static struct node *prev = NULL;
    if (root)
    {
        if (!BST(root->left))
          return false;
        if (prev != NULL && root->data <= prev->data)
          return false;
 
        prev = root;
 
        return BST(root->right);
    }
 
    return true;
}
 
struct node* newnode(int data)
 {   
     struct node* Node=new node;
 	Node->data=data;
 	Node->right=NULL;
 	Node->left=NULL;
 	return (Node);
 }
 int main()
 {
 	struct node* root=newnode(6);
 	root->left=newnode(3);
 	root->right=newnode(8);
 	root->left->left=newnode(7);
 	root->left->right=newnode(5);
 	if (BST(root))
 	  cout<<"tree is BST";
 	else 
 	  cout<<"tree is not BST";
 	  return 0;
 }
 
