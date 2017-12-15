class node
{
int data;
node link;
}
class queue
{
node rear=null;
node top=null;
void push(int x)
{

node temp=new node();
temp.data=x;
if(top==null)
{
rear=temp;
//System.out.print(temp.data);
top=temp;
temp.link=null;
}
else
{
node ptr=rear;
while(ptr.link!=null)
{
ptr=ptr.link;
}
ptr.link=temp;
temp.link=null;
//System.out.print(temp.data);
}
}
void pop()
{
rear=rear.link;
//System.out.print("n");
}
void display()
{
node ptr=rear;
while(ptr!=null)
{
System.out.println(ptr.data+" ");
ptr=ptr.link;
}
}
public static void main(String args[])
{

queue t=new queue();
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
