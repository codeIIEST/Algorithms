package Data_Structures;
import java.util.*;
class Queue
{
	private int q[], front, rear, size;
	
	
	/***** Constructor to initialize queue *****/
	queue(int n)
	{ //Begin constructor
		size = n;
		front = -1;
		rear = -1;
		q = new int[size];
		
		for(int i = 0; i<size; i++)
			q[i] = 0;	
	} //end constructor
	
	
	
	/***** Fucntion to insert an item to queue *****/
	private void insert(int item)
	{ //Begin insert()
		if(rear == (size-1)) //Checks if rear pointer has reached the last limit (Queue is completely full or not) 
		{
			System.out.println("Queue Overflow");
		}
		
		elseif(front == -1 && rear == -1) //Checks if queue is empty to insert the very first element
		{
			front = 0; rear = 0;				
			q[rear] = item;
		}
			
		else
		{
			rear+=1;
			q[rear] = item;
		}
		
	} //End insert()
	
	
	
	
	/***** Fucntion to delete an item from queue *****/
	private void delete()
	{ //Begin delete()
		
		
			if(front == -1 && rear == -1) //Checks if queue is empty
			{
				System.out.println("Queue Underflow");	
			}
			
	
				
				
			elseif(front == rear) //Checks if only one element is present
			{
				System.out.println("Deleted element:\t"+q[front]);
				front = -1; rear = -1;				
			}
				
			else
			{
				System.out.println("Deleted element:\t"+q[front]);					
				front += 1;
			}			
		
	} //End delete()
	
	
	
	/***** Function to display the elements of the queue *****/
	private void display()
	{ //Begin display()
		if(front == - 1 && rear == -1)
		{
			System.out.println("Queue is EMPTY");
		}
		
		else
		{
			System.out.print("Elements of the queue:\nfront ---> ");
			
			for(int i = front; i <= rear; i++)
				System.out.print(q[i]+"\t");
				
			System.out.println("<--- rear");
			
		}
	} //End display()
	
	
	
	
	public static void main(String args[])
	{ //Begin main()
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of the queue");
		int n = sc.nextInt();
		
		queue q1 = new queue(n);
		
		int choice;
		do
		{ //Begin do
			System.out.println("\nEnter:\n1. Insert\n2. Delete\n3. Display");
			choice = sc.nextInt();
			switch(choice)
			{ //Begin switch
				case 1: System.out.println("\nEnter an element to insert");
					int element = sc.nextInt();
					q1.insert(element);
					break;
					
				case 2: q1.delete();
					break;
					
				case 3: q1.display();
					break;
					
				default: System.out.println("Wrong choice. Exitting.");
					break;
			} //End switch
		} //End do
		while(choice >= 1 && choice <= 3);
	} //End main()
} //End class
