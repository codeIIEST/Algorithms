#include<iostream>
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
    node* LCA(node* temp,int val1,int val2)//Here the temp node is a root node.
    {
        if (temp==nullptr)//If the root node is null then return that node
            return temp;
        if(temp->val==val1 || temp->val==val2)//If it equals to any of the value than it should be the lowest common ancestor of that sub tree so, it should be returned.
            return temp;
        else
        {
            node* left = LCA(temp->leftchild,val1,val2);//If it is not equal to any of the value than we go to its child to look for those value.
            node* right = LCA(temp->rightchild,val1,val2);
            if(left!=nullptr && right!=nullptr)//if both right and left are some different  value than null than that must be the lowest common ancestor in that subtree.
                return temp;
            else
            {
            if(left==nullptr && right==nullptr)//If both are null it means that there is no node of that value in the sub tree whose root is the given temp
                return nullptr;
            else
            {
                if(left==nullptr)//If any one of the value is null and other is not than the non-null value has to be the lowest common ancestor.
                    return right;
                else
                    return left;
            }
            }
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
    int val1,val2;
    cin>>val1>>val2;
    node* lca=bst.LCA(temp,val1,val2);
    cout<<"lowest common ancestor of the given nodes is "<<lca->val<<endl;
}






