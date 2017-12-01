/*Removing Duplicate Elements from an unsorted linked list
   Technique Used:Maintain a hash table of data values. We simply iterate
   through the linked list and add the values to the hash table. If we
   encounter a duplicate element we simply remove it by changing pointers.
   Time Complexity-O(n), where n is the total number of elements in the 
   linked list.*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head=NULL;//Head is declared globally to avoid repeated passing between funcitons

/*Hash Table to keep track of data in linked list.
 The first and second column will keep track of postive
 and negative numbers respectively*/
bool hasht[1000001][2]={0};

void Insert(int value)//Function to insert a node at the beginning of the list
{
	Node* newnode=new Node;
	newnode->data=value;
	newnode->next=head;
	head=newnode;
}
void print()
{
	Node* temp=head;
	while(temp->next!=NULL)//Printing upto the second last element to avoid '->' at the end
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<"\n";
}

void Remove_Duplicates()
{
	Node* prev=NULL;
	Node* temp=head;
    
    while(temp!=NULL)//Traversing upto the last node in the linked list
    { 
    	if(temp->data>=0)//Checking for +ve numbers
    	{
    		if(hasht[temp->data][0]==1)//If the number already visited
    		prev->next=temp->next;    //Delete the element by pointing prev to next of current(temp)
    	else
    	{
    		hasht[temp->data][0]=1;  //If not visited, mark visited by making the entry to 1 in the hash table
    		prev=temp;
    	}
    	temp=temp->next;
    }
    else{                            //Block for negative numbers
      {if(hasht[abs(temp->data)][1]==1)
    		prev->next=temp->next;
    	else
    	{
    		hasht[abs(temp->data)][1]=1;
    		prev=temp;
    	}
    	temp=temp->next;
    }
      
    }
}
}


int main()
{
  //Creating the linked list
	Insert(5);
	Insert(4);
	Insert(7);
	Insert(5);
	Insert(4);
	Insert(5);
	Insert(53);
	Insert(8);
	Insert(45);
	Insert(52);
	Insert(6);
	Insert(100);
	Insert(8);
	Insert(5);
	Insert(25);
	Insert(6);
    cout<<"Linked List with duplicates:::\n";
	print();//Printing the linked list before removing the duplicate elements
    
    Remove_Duplicates();//Calling the remove duplicates function
    cout<<"\nLinked Lists after duplicates removed:::\n";
    print();//Calling the print function after deleting redundant elements

  }

