/*C programme for converting in fix to postfix notation
  Data structure - Stacks*/

#include<stdio.h>
#include<assert.h>
#include<string.h>

#define MAXI 100

char stack[MAXI];
int top =-1;

void push(char val)
{
    if(top>= MAXI-1) printf("Stack Overflow\n");
    else stack[++top]= val;
}

void pop()
{
    if(top<0) printf("Stack Underflow\n");
    else top--;
}

void print_stack()
{
    int i;
    for( i=top;i>=0;i--)
        printf("%c ",stack[i]);
    printf("\n");
}

char peek()
{
    //assert(top>=0);
    if(top!=-1)
    return stack[top];
}


int main(void)
{
    char s[] = "(A*B)/C";
    int i;
    push('(');
    for( i=0;i<strlen(s);i++)
    {
        // print_stack();
        // printf("*******\n\n");
        if( (s[i] >='A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') )
            printf("%c " ,s[i]);
        else if(s[i]=='(')
            push(s[i]);
        else if(s[i] == ')')
        {
            while(peek() != '(' && top>=0)
            {
                printf("%c " ,peek());
                pop();
            }
            pop();

        }
        else if(s[i]=='+' || s[i] =='-' )
        {
            if(peek() == '*' || peek() == '/')
            {
                while(peek() != '(')
                {
                    printf("%c ",peek());
                    pop();
                }
                // push();
            }
            else
            {
                push(s[i]);
            }
        }
        else if(s[i]=='*' || s[i] =='/')
            push(s[i]);
    }
    // push(')');
    while(peek() != '(')
    {
        printf("%c ",peek());
        pop();
    }
    // print_stack();
}
