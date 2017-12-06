//Pointer based implementation of Linklist
//All basic operations.
#include<iostream>
using namespace std;
struct node{
	int d;
	node* next;
};


class linklist{
	private:
		node* start;
	
	public:
		linklist();
		void append(int );                        
		void add_beg(int );
		void add_middle(int);
		void add_after(int , int );
		void display();
		void del_middle();
		int count();
		void del(int );	
		void sort();
		linklist reverse();
		void merge(linklist, linklist);
};
//Default constructor
linklist ::  linklist()
{
	//Initialize start with NULL
	start= NULL;
}

//Add element at last of the list
void linklist::append(int x)
{
	//Creating the new node
	node* temp = new node;
	
	//assigning the data in the node                                   
	temp->d=x;
	
	//putting next of the node to NULL                                               
	temp->next= NULL;
	
	//If list is empty
	if(start== NULL)                                         
	{
		start= temp;
	}
	else
	{
		node* t;
		t= start;
		
		//this will find the pointer to last node of the list
		while(t->next!= NULL)
		{
			t=t->next;
		}
		
		//update the last node's next pointer with the pointer to the new node
		t->next= temp;
	}
}

//Add element at the begining of the list
void linklist::add_beg(int x)
{	
	//creating new node
	node* temp= new node;
	
	//assigning the data in the node
	temp->d= x;
	
	//putting nexy of the node to the NULL
	temp->next= NULL;
	
	//If list is empty
	if(start==NULL)
	{
		start= temp;
	}
	else
	{
		//update the next of current node with start
		temp->next= start;
		
		//updating start
		start= temp;
	}
}

//returns the number of nodes in the linklist.
int linklist::count()
{
	int count=0;
	
	//create temporary node
	//assigned it with start 
	node* temp= start;
	
	//traverse the whole list
	while(temp!=NULL)
	{
		//updating count
		count++;
		//updating temp
		temp=temp->next;
	}
	return count;
}

//Add element at the middle of the list
void linklist::add_middle(int x)
{
	//total number of nodes in the list
	int len=count();
	
	int n;
	node* t = start;
	
	//creating new node and assigning the values
	node* temp= new node;
	temp->d=x;
	temp->next=NULL;
	
	//if list has even numbers of node, then add it at len/2
	if(len%2==0)
	n=len/2;
	else
	n=((len/2)+1);
	
	//if the list is empty
	if(n==0)
	{
		start=temp;
		return;
	}
	
	//traversing to the n'th node
	for(int i=1;i<n;i++)
	{
		t=t->next;
	}
	//updating temp
	temp->next=t->next;
	t->next=temp;
	return;
}

//Add element after specific position
void linklist::add_after(int pos, int x)
{
	//creating new node and assigning values in it
	node* temp= new node;
	temp->d=x;
	temp->next=NULL;
	
	node* t = start;
	int len=count();
	
	//if entered position is greater then number of node present in list
	if(pos>len)
	{
		cout<<"Invalid Position To Add Data"<<endl;
	}
	else
	{
		for(int i=1;i<pos;i++)
		{
			t=t->next;
		}
		
		temp->next= t->next;
		t->next= temp;
	}
}

//Display all the contains of linklist.
void linklist::display()
{
	node* t;
	t= start;
	
	while(t!= NULL)
	{
		cout<<t->d<<endl;
		t=t->next;
	}
}

//Delete the middle element from the list
void linklist::del_middle()
{
	int n, len=0;
	node* t= start;
	
	//counting total number of nodes
	len=count();
	
	//if even numbers of nodes are there in the list
	if(len%2==0)
	n= len/2;
	else
	n=(len/2)+1;
	
	//if list is empty
	if(n==0)
	{
		cout<<"List is empty";
		return;
	}
	
	//if there is only 1 element i.e. only start node is there
	if(n==1&& len==1)
	{
		delete start;
		start=NULL;
		return;
	}
	
	//if 2 nodes are present in the list
	if(n==1&& len==2)
	{
		delete start;
		start=t->next;
		return;
	}	
	else														//more than two nodes are there in the list
	{
		//traversed to middle node
		for(int i=1;i<n-1;i++)
		{
			t=t->next;
		}
		node* t1=t->next;
		t->next=t->next->next;
		delete t1;
	}
 } 



//Delete a specific element from the list.
void linklist::del(int x)
{	
	//creating temporary node
	node* temp = start;
	node* t1;
	
	//if start node is that node
	if(start->d== x)
	{
		t1=start->next;
		delete start;
		start= t1;
	}
	else
	{
		int flag=0;
		//traversing to that node
		while(temp->next!=NULL)
		{
			if(temp->next->d== x)
			{
				t1= temp->next->next;
				delete temp->next;
				temp->next = t1;
				flag=1;
				break;
			}
			
			temp= temp->next;
		}
		//if the value is not present in the list
		if(flag==0)
		cout<<"Error: Element Not Found"<<endl;
	}
}

//Sort the given linklist.
void linklist::sort()
{
	node* temp =start;
	int len= count();
	
	node* t;
	//sorting whole list
	while(len--)
	{	
		node* current_node;
		current_node= temp;
		t = temp;
		while(t!=NULL)
		{
			if(current_node->d>t->d)
			{
				swap(current_node->d,t->d);
			}
			t=t->next;
		}
		temp=temp->next;
	}
}

//takes two sorted list in increasing order and merge them.
void linklist::merge(linklist h, linklist k)
{
	//creating two node pointer and initialized with it by start pointers
	node* t1 = h.start;
	node* t2 = k.start;
	
	//traversing till the end of any list
	while(t1!= NULL && t2!= NULL)
	{
	if(t1->d < t2->d)
	{
	node* temp = new node;			
	temp->d= t1->d;
	temp->next= NULL;
	if(start== NULL)
	{
		start = temp;
	}
	else
	{
		node* t;
		t= start;
		while(t->next!= NULL)
		{
			t=t->next;
		}
		t->next= temp;					
	}
	t1= t1->next;	
	}
	else
	{
		node* temp = new node;			
		temp->d= t2->d;
		temp->next= NULL;
		if(start== NULL)
		{
			start = temp;
		}
		else
		{
			node* t;
			t= start;
			while(t->next!= NULL)
			{
				t=t->next;
			}
			t->next= temp;					
		}
		t2= t2->next;
	}
	}
	
	//merge remaining nodes of list 1 if any
	while(t1!=NULL)
	{
		node* temp = new node;
		temp->d= t1->d;
		temp->next= NULL;
		node* t;
		t= start;
		while(t->next!= NULL)
		{
			t=t->next;
		}
		t->next= temp;
		t1= t1->next;
	}
	
	//merge remaining nodes of list 2 if any		
	while(t2!=NULL)
	{
		node* temp = new node;
		temp->d= t2->d;
		temp->next= NULL;
		node* t;
		t= start;
		while(t->next!= NULL)
		{
		t=t->next;
		}
		t->next= temp;
		t2=t2->next;
	}
			
}

//Reverse the elements of the linklist
linklist linklist::reverse()
{
	//reverse the linklist
	node* t=start;
	linklist temp;
	for(int i=1;i<=count();i++)
	{
		//adding the elements from the last to the new linklist
	    temp.add_beg(t->d);
	    t=t->next;
	}
	return temp;
}

//Main function
int main()
{
	linklist l;
	l.append(5);
	l.append(54);
	l.append(64);
	l.append(55);
	l.add_beg(56);
	l.add_beg(88);
	l.add_after(5, 23);
	l.add_after(2, 6);
	l.del(98);
	l.del(45);
	l.add_middle(5);
	l.del_middle();
	
	l.display();
	l=l.reverse();
	cout<<"Reversed linklist data"<<endl;
	l.display();
	cout<<"no. of elements in given list ="<<l.count()<<endl;
	cout<<"List after sorting"<<endl;
	l.sort();
	l.display();
	return 0;
}
