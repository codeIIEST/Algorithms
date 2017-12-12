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

lli sum(lli T[] , lli index){
    lli sum = 0;
    index+=1;
    while(index > 0){
        sum += T[index]   ;
        index = index - (index&(-1*index));
    }
    return sum ;
}
void update(lli T[] , lli n , lli index  , lli value ){
    index++;
    while(index <= n){
        T[index] += value ;
        index = index + (index&(-1*index));
    }
}
lli * binary_indexed_tree(lli n){
    lli i ;
    lli* T =(lli *) malloc(sizeof(lli)*200002) ;
    for(i = 1 ; i <= n+1 ; i++)
        {
            T[i] = 0  ;
    }
    // for(i = 0 ; i < n ; i++)
    //     {
    //         update(T,n,i,a[i]) ;
    // }
    return T ;
}
int main() {
    lli test,n,i,j,query,option,ans,p,q,v;
    lli arr[200002];
    cin>>test;
    while(test--)
    {
        cin>>n;
        cin>>query;
        fr(i,0,n)
        {
            arr[i] = 0;
        }
        lli* T1 = binary_indexed_tree(n);
        lli* T2 = binary_indexed_tree(n);
        while(query--)
        {
            cin>>option>>p>>q ;
            p--;
            q--;
            if(option == 0)
            {
                cin>>v;
                update(T1,n,p,v);
                update(T1,n,q+1,-v);
                update(T2,n,p,v*(p-1));
                update(T2,n,q+1,-v*q);
            }
            else
            {
                ans = sum(T1,q)*q-sum(T2,q)-sum(T1,p-1)*(p-1)+sum(T2,p-1) ; 
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
