/*Print a Binary Tree in Vertical Order using Hash Table(Recursively)
  Algorithm:The nodes whicb are the smae distance from the root of tree
  are considered to be at the same vertical line. The distance of the left node is minus 1 
  from the root, and right node is +1 from the root. A hash map is maintained that stores
  the distance from the root and the corresponding nodes with the help of key value pairs.
  Time Complexity-O(nlogn) as maps are used which are implemented using AVL trees where all
  operations take place in O(logn) time
  */

#include<bits/stdc++.h>
using namespace std;

//Structure fro a node of the tree
struct Node{
	int data;
	Node* left;
	Node* right;
};

//Creates a node and returns it
Node* newnode(int x)
{
	Node* temp=new Node;
	temp->data=x;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
//Stores the horizontal distances and nodes recursively using maps
void PreOrder(map<int,vector<int>>&m, Node* root,int d)
{
	if(root==NULL)//Base Case
		return;
	m[d].push_back(root->data);//The root data is fed to the map
	PreOrder(m,root->left,d-1);//Recursive Calls to left subtree with distance-1
	PreOrder(m,root->right,d+1);//Recursive Calls to right subtree with distance+1
}

//
void VerticalOrder(Node* root)
{
	map<int,vector<int>>hasht;
	int d=0;//Horizontal Distance of root
	PreOrder(hasht,root,d);


	map<int,vector<int>>::iterator it;
	for(it=hasht.begin();it!=hasht.end();it=it+1)//Loops to print the values in the hashmap
	{
		for(int i=0;i<it->second.size();i++)
			cout<<it->second[i]<<" ";
		cout<<endl;
	}

}

int main()
{   //The tree is built
	Node* root=new Node;
	root->data=1;
	root->left=newnode(2);
	root->right=newnode(17);
	root->left->left=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(8);
	root->right->right->right=newnode(9);
	root->left->right=newnode(4);
	root->right->left->right=newnode(8);
	VerticalOrder(root);

	return 0;
}
