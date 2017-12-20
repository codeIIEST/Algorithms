#include<iostream.h>
#include<constream.h>
template<class T>
class LinearList
{
	private:
		int length;
		int MaxSize;
		T *element;
	public:
		explicit LinearList(int MaxLinearSize=10);           //To create  a Linked List [A Constructor]
		LinearList(const LinearList &L);                            //A Copy Constructor
		~LinearList(){delete[]element;}                      //To delete the Linked List from the memory [A Destructor] 
		int isEmpty()const{return length==0;}                //To check if the Linked List is empty
		int Length()const{return length;}                    //To find the length of a Linked List
		int Find(int k,T&x)const;                            //To get the Value at the given position of the Linked List 
		int Search(const T&x)const;                          //To check if an element is present in the Linked List 
		void Delete(int k,T&x);                              //To delete a specific element from a Linked List 
		void Insert(int k,const T&x);                        //To insert an element onto a Linked List 
		void Output()const;                                  //To display the Linked List 
};
	template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize=MaxListSize;
	element=new T[MaxSize];
	length=0;
}
template<class T>
int LinearList<T>::Find(int k,T&x)const
{
	if(k<1||k>length)
		return 0;
	x=element[k-1];
	return 1;
}
template<class T>
int LinearList<T>::Search(const T&x)const
{
	for(int i=0;i<length;i++)
		if(element[i]==x)
			return ++i;
	return 0;
}
	template<class T>
void LinearList<T>::Delete(int k,T&x)
{
	if(Find(k,x))
	{
		for(int i=k;i<length;i++)
			element[i-1]=element[i];
		length--;
	}
	else
		cout<<"out of bounds\n";
}
	template<class T>
void LinearList<T>::Insert(int k,const T&x)
{
	if(k<0||k>length)
		cout<<"out of bounds\n";
	if(length==MaxSize)
		cout<<"no memory\n";
	for(int i=length-1;i>=k;i--)
		element[i+1]=element[i];
	element[k]=x;
	length++;
}
template<class T>
void LinearList<T>::Output()const
{
	if(isEmpty())
		cout<<"list is empty\n";
	else
		for(int i=0;i<length;i++)
			cout<<element[i]<<"\t";
}
void menu()
{
	cout<<"\n MENU\n" ;
	cout<<"-----------\n";
	cout<<"1.Length\n";
	cout<<"2.Find\n";
	cout<<"3.Search\n";
	cout<<"4.Delete\n";
	cout<<"5.Insert\n";
	cout<<"6.Output\n";
	cout<<"-------------\n";
}
void main()
{
	int ch;
	int k,x,len,p;
	clrscr();
	LinearList <int> obj;
	do
	{
		menu();
		cout<<"enter choice\t";
		cin>>ch;
		switch(ch) {
			case 1:
				len=obj.Length();
				if(len==0)
					cout<<"List is empty\n";
				else
					cout<<"length of linearlist is "<<len<<endl;
				break;
			case 2:
				cout<<"enter k,x(position and value)\n";
				cin>>k>>x;
				p=obj.Find(k,x);
				if(p==1)
					cout<<"found"<<endl;
				if(p==0)
					cout<<"not found"<<endl;
				break;
			case 3:
				cout<<"enter x(value)\n";
				cin>>x;
				p=obj.Search(x);
				if(p)
					cout<<"searching is sucessful and found at"<<p<<endl;
				else
					cout<<"searching not sucessful"<<endl;
				break;
			case 4:
				cout<<"enter k,x(position and value)\n";
				cin>>k>>x;
				obj.Delete(k,x);
				break;
			case 5:
				cout<<"enter k,x(index and value)\n";
				cin>>k>>x;
				obj.Insert(k,x);
				break;
			case 6:
				cout<<"elements in the list are:\n\n";
				obj.Output();
				break;
			default:
				cout<<"invalid choice\n";
				break;
		}  } while(ch>=1&&ch<=6);
		getch();
}