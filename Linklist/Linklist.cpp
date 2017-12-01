//Pointer based implementation of Linklist
//All basic operations.
#include<iostream>
using namespace std;
#include<conio.h>
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
	start= NULL;
}

//Add element at last of the list
void linklist::append(int x)
{
	node* temp = new node;
	temp->d=x;
	temp->next= NULL;
	
	if(start== NULL)
	{
		start= temp;
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
}

//Add element at the begining of the list
void linklist::add_beg(int x)
{
	node* temp= new node;
	temp->d= x;
	temp->next= NULL;
	
	if(start==NULL)
	{
		start= temp;
	}
	else
	{
		temp->next= start;
		start= temp;
	}
}

//Add element at the middle of the list
void linklist::add_middle(int x)
{
	int count=0;
	int n;
	node* t = start;
	node* temp= new node;
	temp->d=x;
	temp->next=NULL;
	while(t!=NULL)
	{
		count++;
		t=t->next;
	}
	t=start;
	if(count%2==0)
	n=count/2;
	else
	n=((count/2)+1);
	if(n==0)
	{
		start=temp;
		return;
	}
	for(int i=1;i<n;i++)
	{
		t=t->next;
	}
	temp->next=t->next;
	t->next=temp;
	return;
}

//Add element after specific position
void linklist::add_after(int n, int x)
{
	node* temp= new node;
	temp->d=x;
	temp->next=NULL;
	
	node* t = start;
	int count=0;
	while(t!= NULL)
	{
		count++;
		t=t->next;
	}
	t=start;
	
	if(n>count)
	{
		cout<<"Invalid Position To Add Data"<<endl;
	}
	else
	{
		for(int i=1;i<n;i++)
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
	int n, coun=0;
	node* t= start;
	coun=count();
	if(coun%2==0)
	n= coun/2;
	else
	n=(coun/2)+1;
	if(n==0)
	{
		cout<<"List is empty";
		return;
	}
	if(n==1&& coun==1)
	{
		delete start;
		start=NULL;
		return;
	}
	if(n==1&& coun==2)
	{
		delete start;
		start=t->next;
		return;
	}
	else
	{
		for(int i=1;i<n-1;i++)
		{
			t=t->next;
		}
		node* t1=t->next;
		t->next=t->next->next;
		delete t1;
	}
 } 

//Count the elements in the linklist.
int linklist::count()
{
	int count=0;
	node* temp= start;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

//Delete a specific element from the list.
void linklist::del(int x)
{
	int flag=0;
	node* temp = start;
	node* t1;
	if(start->d== x)
	{
		t1=start->next;
		delete start;
		start= t1;
	}
	else
	{
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
		if(flag==0)
		cout<<"Error: Element Not Found"<<endl;
	}
}

//Sort the given linklist.
void linklist::sort()
{
	node* temp =start;
	int n= count();
	node* cnode;
	node* t;
	while(n--)
	{
		cnode= temp;
		t = temp;
		while(t!=NULL)
		{
			if(cnode->d>t->d)
			{
				swap(cnode->d,t->d);
			}
			t=t->next;
		}
		temp=temp->next;
	}
}

//Merge two sorted linklist.
void linklist::merge(linklist h, linklist k)
{
	node* t1 = h.start;
	node* t2 = k.start;
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
	node* t=start;
	linklist temp;
	for(int i=1;i<=count();i++)
	{
	    temp.add_beg(t->d);
	    t=t->next;
	}
	return linklist;
}

//Main function
int main()
{
	linklist l;
	l.append(5);
	l.append(5455);
	l.append(645);
	l.append(545);
	l.add_beg(56);
	l.add_beg(898);
	l.add_after(5, 23);
	l.add_after(2, 56);
	l.del(898);
	l.del(545);
	l.add_middle(45);
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
