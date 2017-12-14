#include<bits/stdc++.h>
using namespace std;

#define md 1000000007
#define ll long long int
#define vi vector<int>
#define vll vector<i64>
#define pb push_back
#define all(c) (c).begin(),(c).end()
int main()
{

    int n;
    cin>>n;//Input the number of elements in the array.
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];//read all the elements
    }
    int cols = log(n)/log(2);//Cols represent the no of coloumns in the sparse table .
    int rows = n;//rows represent the no of rows in the sparse table
    int lookup[rows][cols+1];
    for(int i=0;i<=cols;i++)//This is the procedure to build a sparse table
    {

        for(int j=0;j<rows;j++)
        {
            if(i==0)
                lookup[j][i]=j;
            else
            {

                if(j+pow(2,i)<=n)
                {

                    if(a[lookup[j+(int)pow(2,i-1)][i-1]]>a[lookup[j][i-1]])//This is the procedure to create a sparse table for range minimum query. This statement of code can be appropriately changed for another type of query.
                    lookup[j][i]=lookup[j][i-1];
                    else
                        lookup[j][i] = lookup[j+(int)pow(2,i-1)][i-1];

                }
            }
            //cout<<stable[j][i]<<endl;
        }
    }

    int left,right;
    cin>>left>>right;
    int k = right-left+1;//This represent the total length of the query range.

    int col = (int)(log(k)/log(2));//This represent the coloumn we first look for in the sparse table.

    int min1 = a[lookup[left-1][col]];
    int remaining = k- pow(2,col);
    int min2 = a[lookup[left+remaining-1][col]];

    cout<<"minimum in the given range is :"<<min(min1,min2)<<endl;


}
