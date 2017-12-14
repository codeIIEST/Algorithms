package Data_Structures
import java.util.*;
class stack
{ //Begin class

	int top = -1, size, s[];
	
	
	/*****Constructor to initialise the stack *****/
	stack(int n)
	{ //Begin constructor
		size = n;
		
		s = new int[size];		
		for(int i = 0; i < size; i++)
		{ //Begin for
			s[i] = 0;
		} //End for			
	} //End constructor
		
		
		
	/***** Fucntion to insert/push item to stack *****/
	private void push(int item)
	{ //Begin push()
	
		if(top == (size-1)) //Checks if stack is full
		{ //Begin if
			System.out.println("Stack overflow");
		} //End if
		
		else //Element is entered to the stack when there is place
		{ //Begin else
			top++;
			s[top] = item;
		} //End else
		
	} //End push()
	
	
	
	/***** Function to delete/pop an item (topmost element) from stack *****/
	private void pop()
	{ //Begin pop()
		
		if(top == -1) //Checks if stack is empty
		{ //Begin if
			System.out.println("Stack underflow");
		} //End if
		
		else
		{ //Begin else
			System.out.println("Item deleted is:\t"+s[top]);
			top--;
		} //End else
	} //End pop()
	
	
	/***** Function to peep (show the topmost element in stack) *****/
	private void peep()
	{ //Begin peep()
		if(top == -1)
			System.out.println("No element to peep");
		
		else
			System.out.println("Peep: top ---> "+s[top]);
	} //End peep()
	
	
	
	/***** Function to display the elements of stack *****/
	private void display()
	{ //Begin display()
				
		if(top == -1)
		{ //Begin if
			System.out.println("No elements in stack");
		} //End if
		
		else
		{ //Begin else
			
			System.out.print("Elements of the stack: top---> ");
			for(int i=top; i>=0; i--)
			{
				System.out.print(s[i]+"\t");
			}
			System.out.println();
		} //End else
	} //End display()
	
	
	/***** main fucntion *****/
	public static void main(String args[])
	{ //Begin main()
	
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of the stack");
		int n = sc.nextInt();
		
		stack st = new stack(n);
		
		int choice;
		do
		{ //Begin do
			System.out.println("\nEnter:\n1. Push\n2. Pop\n3. Peep\n4. Display");
			choice = sc.nextInt();
			switch(choice)
			{ //Begin switch
				case 1: System.out.println("\nEnter an element to push");
					int element = sc.nextInt();
					st.push(element);
					break;
					
				case 2: st.pop();
					break;
					
				case 3: st.peep();
					break;
				
				case 4: st.display();
					break;
					
				default: System.out.println("Wrong choice. Exitting!");
					break;
			} //End switch
		} //End do
		while(choice >= 1 && choice <= 4);
	} //End main()
} //End class
