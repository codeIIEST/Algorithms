/*Problem Statement -->
To initialize a given array in constant time. In many situations we have to initialize an array of very large size. We don't want the runtime of the array to be dominated by initialization time. So, we have to initialize the array in constant time.


To show strongly recommend and practice link 

Solution:
For a n-element array arr[], we'll use two additional n-element arrays and a pointer. The arrays are called from and to and the pointer is called ptr. The initial value can be called init_val.
When an element i from arr[] is accessed, the condition to know whether it has been initialized is, if from[i]&lt;ptr and to[from[i]] = i. If this condition is satisfied, we return arr[i], else we return the init_val.
Initially, ptr is 0.

The array element i is first accessed by the code:
<pre>
from[i]=top;
to[ptr]=i;
arr[i]=init_val;
ptr++;

Understanding the algorithm

Let us assume we want an array with size 10. This is the initial state of the array and helpers (* denotes a memory location with garbage value):

arr:  * * * * * * * * * *
from: * * * * * * * * * *
to:   * * * * * * * * * *
ptr:  0

Since from and to contain unsigned values, the condition from[i] &lt; ptr can never be true while ptr = 0. So at this point all read accesses will return us the value init_val.

Now suppose we want to write into the array. Let&#039;s say we want to write value 5 into arr[6]. According to the algorithm, the next state will be:

arr:  * * * * * * 5 * * *
from: * * * * 1 * 0 * * *
to:   6 * * * * * * * * *
ptr:  1

At this point if we want to access arr[5], then the conditions from[i]&lt;top and to[from[i]]==i will both be satisfied and we will be returned the value arr[i].
Writing one more value to arr[4]=6, we will have the following:

arr:  * * * * 6 * 5 * * *
from: * * * * 1 * 0 * * *
to:   6 4 * * * * * * * *
ptr:  2

At this point if we want to access arr[4], then the conditions from[4]&lt;ptr and to[from[4]]==4 will both be satisfied and we will be returned the value arr[4]=5. For all the remaining uninitialized indexes, access will fail.

In this way, the two arrays from and to with the help of ptr, helps us to initialise an array in constant time. Additional space of O(n) is required.*/

#include<iostream>
#include<cstddef>

using namespace std;

class Array{
public:
     Array(size_t len, int val= 0)
    {
        arr= new int[len];
        from = new size_t[len];
        to = new size_t[len];
        ptr = 0;
        init_val = init_val;
        size = len;
    }

    int& operator[](size_t n)  
    {
        if (from[n] < ptr && to[from[n]] == n)//Condition to check whether that index i is already initiazed
            return arr[n];                    //Returning the already initiased value
        else
        {
            from[n] = ptr;                    //We are initialsing the array with the init value if it is not initialised
            to[ptr] = n;
            arr[n] = init_val;
            ptr++;
            
            return arr[n];                     //This will return the element initialised with init_value
        }
    }

    ~Array()                                   //Destructor
    {
        delete[] arr;
        delete[] from;
        delete[] to;
    }
    
private:
    int* arr;
    size_t* from;
    size_t* to;
    size_t ptr;
    int init_val;
    size_t size;
};

int main()
{
   Array array(10, 1);//we want the array to be initialised with the value 1
   
   cout<<"array[4]:"<<array[4]<<endl;
   cout<<"array[7]:"<<array[7]<<endl;
   
   array[4]=100;
   cout<<"\narray[4]:"<<array[4]<<endl;
   cout<<"array[7]:"<<array[7]<<endl;


}
