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
lli T[200002]={0} ;
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
lli * binary_indexed_tree(lli *a, lli n){
    lli i ;
    for(i = 1 ; i <= n+1 ; i++)
        {
            T[i] = 0  ;
    }
    for(i = 0 ; i < n ; i++)
        {
            update(n,i,a[i]) ;
    }
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
        binary_indexed_tree(arr,n);
        while(query--)
        {
            cin>>option>>p>>q ;
            p--;
            q--;
            if(option == 0)
            {
                cin>>v;
                update(n,p,v);
                if(q != n-1)
                    update(n,q+1,-1*v);
            }
            else
            {
                if(p == 0)
                    ans = sum(q);
                else
                    ans = sum(q)-sum(p-1) ; 
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
