// C program to show segment tree operations like construction, query
// and update
#include <stdio.h>
#include <math.h>
 
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.
 
    pointertotree    --> Pointer to segment tree
    current_node    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0
    startsegement & endsegement  --> Starting and ending indexes of the segment represented
                 by current node, i.e., pointertotree[current_node]
    querry_start & querry_end  --> Starting and ending indexes of query range */
int getSumUtil(int *pointertotree, int startsegement, int endsegement, int querry_start, int querry_end, int current_node)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    if (querry_start <= startsegement && querry_end >= endsegement)
        return pointertotree[current_node];
 
    // If segment of this node is outside the given range
    if (endsegement < querry_start || startsegement > querry_end)
        return 0;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(startsegement, endsegement);
    return getSumUtil(pointertotree, startsegement, mid, querry_start, querry_end, 2*current_node+1) +
           getSumUtil(pointertotree, mid+1, endsegement, querry_start, querry_end, 2*current_node+2);
}
 
/* A recursive function to update the nodes which have the given 
   index in their range. The following are parameters
    pointertotree, current_node, startsegement and endsegement are same as getSumUtil()
    i    --> index of the element to be updated. This index is 
             in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(int *pointertotree, int startsegement, int endsegement, int i, int diff, int current_node)
{
    // Base Case: If the input index lies outside the range of 
    // this segment
    if (i < startsegement || i > endsegement)
        return;
 
    // If the input index is in range of this node, then update 
    // the value of the node and its children
    pointertotree[current_node] = pointertotree[current_node] + diff;
    if (endsegement != startsegement)
    {
        int mid = getMid(startsegement, endsegement);
        updateValueUtil(pointertotree, startsegement, mid, i, diff, 2*current_node + 1);
        updateValueUtil(pointertotree, mid+1, endsegement, i, diff, 2*current_node + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(int arr[], int *pointertotree, int n, int i, int new_val)
{
    // Check for erroneous input index
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    // Get the difference between new value and old value
    int diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(pointertotree, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index querry_start (quey start)
// to querry_end (query end).  It mainly uses getSumUtil()
int getSum(int *pointertotree, int n, int querry_start, int querry_end)
{
    // Check for erroneous input values
    if (querry_start < 0 || querry_end > n-1 || querry_start > querry_end)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(pointertotree, 0, n-1, querry_start, querry_end, 0);
}
 
// A recursive function that constructs Segment Tree for array[startsegement..endsegement].
// current_node is index of current node in segment tree pointertotree
int constructSTUtil(int arr[], int startsegement, int endsegement, int *pointertotree, int current_node)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (startsegement == endsegement)
    {
        pointertotree[current_node] = arr[startsegement];
        return arr[startsegement];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = getMid(startsegement, endsegement);
    pointertotree[current_node] =  constructSTUtil(arr, startsegement, mid, pointertotree, current_node*2+1) +
              constructSTUtil(arr, mid+1, endsegement, pointertotree, current_node*2+2);
    return pointertotree[current_node];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    // Allocate memory
    int *pointertotree = new int[max_size];
 
    // Fill the allocated memory pointertotree
    constructSTUtil(arr, 0, n-1, pointertotree, 0);
 
    // Return the constructed segment tree
    return pointertotree;
}
 
// Main
int main()
{
    int arr[] = {0, 2, 5, 6, 10, 13};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    // Build segment tree from given array
    int *pointertotree = constructST(arr, n);
 
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %dn", 
            getSum(pointertotree, n, 1, 3));
 
    // Update: set arr[1] = 10 and update corresponding 
    // segment tree nodes
    updateValue(arr, pointertotree, n, 1, 10);
 
    // Find sum after the value is updated
    printf("\nUpdated sum of values in given range = %dn",
             getSum(pointertotree, n, 1, 3));
    return 0;
} 
