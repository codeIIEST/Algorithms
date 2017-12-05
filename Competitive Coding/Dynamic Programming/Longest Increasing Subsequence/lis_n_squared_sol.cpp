#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define infinite 0xffff
#define Min(a,b)  (((a)<(b))?(a):(b))
#define Max(a,b)  (((a)>(b))?(a):(b))
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define ifr(i,j,s) for(i = j ; i >= s ; i--)
void lis(lli * a, lli n)
{
    lli i,j,count;
    lli record[n];
    //Code to generate the map
    fr(i,0,n)
    {
        record[i] = 0 ;
    }
    fr(i,0,n)
    {
        fr(j,0,i)
        {
            if( (a[i]>a[j]) && (record[i]<(record[j]+1)) )
            {
                record[i]=record[j]+1;
            }
        }
    }
    lli max = 0;
    lli index = 0 ;
    fr(i,0,n)
    {
        //cout<<record[i]<<" ";
        if(max < record[i])
        {
            max = record[i];
            index = i ;
        }
    }
    lli sub[max+1];
    lli temp = max+1;
    lli ns = max ;
    lli prev = index;
    sub[ns]=a[index];
    ns--;
    ifr(i,index,0)
    {
        if(( record[i] == (max-1) ) && ( a[i] < a[prev] ) )
        {
            sub[ns]=a[i];
            ns--;
            prev=i;
            max--;
        }
    }
    //cout<<endl;
    fr(i,0,temp)
    {
        cout<<sub[i]<<" ";
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
