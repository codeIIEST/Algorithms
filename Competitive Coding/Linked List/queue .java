package LinkedList;
public class Node
{
public int data;
public Node link;
}
public class Queue
{
public Node rear=null;
public Node top=null;
public void push(int x)
{

Node temp=new Node();
temp.data=x;
if(top==null)
{
rear=temp;
top=temp;
temp.link=null;
}
else
{
Node ptr=rear;
while(ptr.link!=null)
{
ptr=ptr.link;
}
ptr.link=temp;
temp.link=null;
}
}
public void pop()
{
rear=rear.link;
}
public void display()
{
Node ptr=rear;
while(ptr!=null)
{
System.out.println(ptr.data+" ");
ptr=ptr.link;
}
}
public static void main(String args[])
{
Queue t=new Queue();
t.push(1);
t.push(2);
t.push(3);
t.push(4);
t.push(5);
t.push(6);
t.pop();
t.display();
}
}
