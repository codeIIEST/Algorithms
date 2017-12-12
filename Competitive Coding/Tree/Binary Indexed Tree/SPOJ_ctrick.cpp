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

lli hash_array_mod[200002]={0};

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
    for(i = 0 ; i < n ; i++)
        {
            update(T,n,i,1) ;
    }
    return T ;
}
void renew(lli* T,lli n)
{
    lli i ;
    for(i = 1 ; i <= n+1 ; i++)
        {
            T[i] = 0  ;
    }
    for(i = 0 ; i < n ; i++)
        {
            update(T,n,i,1) ;
    }
}

lli modified_binary_search(lli * T, lli val, lli start , lli end)
{
    lli mid = (start+end)/2 ;
    lli mid_sum = sum(T,mid) ; 
    if((mid_sum == val)&&(hash_array_mod[mid+1] == 0))
        return mid;
    else if( (mid_sum > val) || ((mid_sum == val)&&(hash_array_mod[mid+1] != 0)) )
    {
        return modified_binary_search(T,val,start,mid-1);
    }
    else
    {
        return modified_binary_search(T,val,mid+1,end);
    }
} 
int main() {
    lli test,n,i,j,ans,current_pos,next_pos_sum,next_pos,count,free_space_total;
    lli a[200002];
    cin>>test;
    lli* T = binary_indexed_tree(n);
    while(test--)
    {
        cin>>n;
        //cin>>query;
        if(n == 1)
        {
            cout<<"1"<<endl;
            continue ;
        }
        fr(i,0,n+1)
        {
            hash_array_mod[i] = 0 ;
        }
        renew(T,n);
        a[2] = 1 ;
        free_space_total = n-1 ;
        current_pos = 2 ;
        next_pos_sum = 2 ;
        count = 2 ;
        hash_array_mod[2] = 1 ;
        update(T,n,1,-1); // 0 due to difference in indexing of the BIT ADT and the input formats.
        while(free_space_total)
        {
            next_pos_sum = ((sum(T,current_pos-1)+count)%free_space_total) + 1 ;
            next_pos = modified_binary_search(T,next_pos_sum,0,n-1);
            next_pos+=1;
            a[next_pos] = count;
            hash_array_mod[next_pos] = 1 ;
            current_pos = next_pos ;
            count++;
            free_space_total--;
            update(T,n,next_pos-1,-1);
        }
        fr(i,1,n+1)
        {
            cout<<a[i]<<" "; 
        }
        cout<<endl;
    }
    return 0;
}