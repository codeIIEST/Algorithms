#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define infinite 0xffff
#define Min(a,b)  (((a)<(b))?(a):(b))
#define Max(a,b)  (((a)>(b))?(a):(b))
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define ifr(i,j,s) for(i = j ; i >= s ; i--)
lli binary_LookUp(lli * record ,lli a , lli len , lli val)
{
    while(len-a > 1)
    {
        lli m = a + (len-a)/2;
        if(record[m]>=val)
        {
            len = m ;
        }
        else
        {
            a = m ;
        }
    }
    return len ;
}
void lis(lli * a, lli n)
{
    lli i,j,count,index;
    lli record[n];
    //Code to generate the map
    record[0]=a[0];
    lli len = 1 ;
    fr(i,1,n)
    {
        if(a[i]<record[0])
        {
            record[0] = a[i];
        }
        else if(a[i] > record[len-1])
        {
            record[len] = a[i];
            len++;
        }
        else
        {
            index=binary_LookUp(record,-1,len-1,a[i]);
            record[index] = a[i];
        }
    }
    cout<<len<<endl;
    fr(i,0,len)
    {
        cout<<record[i]<<" ";
    }
    cout<<endl;
}
int main(void)
{
    lli n,i;
    cin>>n;
    lli a[n];
    fr(i,0,n)
    {
        cin>>a[i];
    }
    lis(a,n);
    return 0;
}
