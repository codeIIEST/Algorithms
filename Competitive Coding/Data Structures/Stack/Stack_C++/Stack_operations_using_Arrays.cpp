
// All Operations on Stacks based on ARRAYS
//--------------------------------------------------------------------------------------

#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class stack
{
             int stk[101];
             int top;

      public:

             stack()                                         // Initialising an Empty Stack
              {
                top=-1;
              }


             void push(int x)                               // To Insert Elements onto the Stack
              {
                 if(top >  100)                             // To Check if the Stack is already FULL 
                       {
                           cout <<"\n\n !!!! Stack over flow !!!!";
                           return;
                       }
                 stk[++top]=x;
                 cout <<"\n The inserted element is : \t" <<x;     // Inserting a NEW element and making it the NEW Top
               }


             void pop()                                    // To Delete an element from the Stack
               {
                  if(top <0)                               // To check if the Stack is already EMPTY
                   {
                         cout <<"\n\n !!!! Stack under flow !!!!";
                         return;
                    }
                    cout <<"deleted" <<stk[top--];         // Deleting an element and making the PREVIOUS element the NEW TOP
                }


             void display()                               // To Display the Stack
               {
                   if(top<0)
                    {
                            cout <<"\n\n Stack is empty :(";
                            return;
                    }
                    for(int i=top;i>=0;i--)
                    {
                        if (i == top)
                          cout<<"\n Top -->  ";
                        cout <<stk[i] <<"    ";                        
                    }
                }
};
 
main()
{
     int ch;
     int ele;
     stack st;
     while(1)
        {
            cout << "\n What do you want to do?"
                 << "\n\n 1. Push an element onto the Stack"
                 << "\n\n 2. Pop  an element from the Stack"
                 << "\n\n 3. Display the Stack"
                 << "\n\n 4. EXIT the program"
                 << "\n\n\n\n Please Enter your choice\n";
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "\n Enter the element \t:\t";
                cin >> ele;
                st.push(ele);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.display();
                break;
            case 4:
                exit(0);
               }
         }
return (0);
}