#include<iostream>
#include<vector>
using namespace std;
#define nullptr 0
typedef struct elem
{
    int val;
    struct elem* leftchild;
    struct elem* rightchild;
    struct elem* parent;
}node;//This is the node for the binary tree. Each element in the binary tree contains a value, a pointer to left child,right child and parent.
class BinaryTree
{
private:
    int n=0;
    node* root=nullptr;
public:
    void insert(int x)//Insert function first searches for the place where the node can be inserted and then it inserts it there.
    {

        if(n==0)
        {
            root=new node;
            root->val=x;
            root->leftchild=nullptr;
            root->rightchild=nullptr;
            root->parent=nullptr;
        }
        else
        {
            node* temp=root;
            node* newnode=searchnode(x,temp);
            if(x>newnode->val)
            {
                newnode->rightchild=new node;
                newnode->rightchild->val=x;
                newnode->rightchild->parent=newnode;
                newnode->rightchild->leftchild=nullptr;
                newnode->rightchild->rightchild=nullptr;
            }
            else
            {
                newnode->leftchild=new node;
                newnode->leftchild->val=x;
                newnode->leftchild->parent=newnode;
                newnode->leftchild->leftchild=nullptr;
                newnode->leftchild->rightchild=nullptr;
            }

        }
        n++;

    }

    node* searchnode(int x,node* temproot)//The search function searches for the node whose value is equal to  the value it is searching for.It takes O(log n) as it is proportional to the height of the binary tree.
    {

          if(temproot->val<x)//If value is smaller than it goes to the right child
            {
                if(temproot->rightchild!=nullptr)
                searchnode(x,temproot->rightchild);
                else
                    return temproot;
            }
                else
                {
                    if(temproot->val>x)//If value if larger it goes to the left child
                {
                    if(temproot->leftchild!=nullptr)
                    searchnode(x,temproot->leftchild);
                    else
                        return temproot;
                }
                else
                {
                    if(temproot->val==x)//It returns the value when it is equal
                        return temproot;
                }
                }

    }
    void printtree(node* temp)
    {
        if(temp==nullptr)
            return;
        else
            {
                printtree(temp->leftchild);
                cout<<temp->val;
                printtree(temp->rightchild);
            }
    }//This is the function to print the tree. It prints the tree in a sorted order.
    node* giveroot()
    {
        return root;
    }//This function returns the pointer to root
    void inorder_traversal(node* temp)
    {
        if(temp==nullptr)
            return ;
        else
        {
            inorder_traversal(temp->leftchild);
            cout<<temp->val<<endl;
            inorder_traversal(temp->rightchild);
        }
    }
   
};
int main()
{
    int n;
    cin>>n;
    BinaryTree bst;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        bst.insert(temp);
    }
    node* temp=bst.giveroot();

   // bst.printtree(temp);
    //temp = bst.giveroot();
    bst.inorder_traversal(temp);
    
}






