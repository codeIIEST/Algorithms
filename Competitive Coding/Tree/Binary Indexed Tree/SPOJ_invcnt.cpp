// Solution to ...https://www.hackerrank.com/challenges/insertion-sort
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int
#define Min(a,b)  (a<b?a:b)
#define Max(a,b)  (a<b?b:a)
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define ufr(i,j,s) for(i = j ; i > s ; i--)

//lli sum( lli index) : returns of arr[index]+arr[index-1]..arr[0]

//void update( lli n , lli index  , lli value ) : adds v to arr[index] 


lli T[100002]={0} ;
lli sum(lli index){
    lli sum = 0;
    index+=1;
    while(index > 0){
        sum += T[index]   ;
        index = index - (index&(-1*index));
    }
    return sum ;
}
void update(lli n , lli index  , lli value ){
    index++;
    while(index <= n){
        T[index] += value ;
        index = index + (index&(-1*index));
    }
}
void binary_indexed_tree(lli *a, lli n){
    lli i ;
    for(i = 1 ; i <= n+1 ; i++)
        {
            T[i] = 0  ;
    }
    //To be Uncommented as per the need
    /*for(i = 0 ; i < n ; i++)
        {
            update(n,i,a[i]) ;
    }*/
}
int main() {
    lli test,n,i,j,inversions,position,option,ans,p,q,v;
    lli arr[100002];
    lli brr[100002];
    cin>>test;
    while(test--)
    {
        inversions = 0;
        cin>>n;
        fr(i,0,n)
        {
            cin>>arr[i];
            brr[i] = arr[i] ;
        }
        sort(brr,brr+n);
        fr(i,0,n)
        {
            position = ( lli )(lower_bound(brr,brr+n,arr[i])-brr);
            arr[i] = position+1 ;
        }
        binary_indexed_tree(arr,n);
        ufr(i,n-1,-1)
        {
            inversions += sum(arr[i]-1);
            update(n,arr[i],1);
        }
        cout<<inversions<<endl;
        
    }
    return 0;
}
