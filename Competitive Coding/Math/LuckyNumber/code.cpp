#include <stdio.h>
#define bool int
 

bool isLucky(int n)     /* Returns 1 if n is a lucky no. ohterwise returns 0*/
{
    static int counter = 2;
     
    
    int next_position = n;  /*variable next_position is just for readability of
                             the program we can remove it and use n only */
    if(counter > n)
        return 1;
    if(n%counter == 0)
        return 0;    
     
    
    next_position -= next_position/counter;   /*calculate next position of input no*/
     
    counter++;
    return isLucky(next_position);
}
 
int main()
{
    int x = 5;
    if( isLucky(x) )
        printf("%d is a lucky no.", x);
    else
        printf("%d is not a lucky no.", x);
    getchar();
}

/*output*/
Output:
5 is not a lucky no.
