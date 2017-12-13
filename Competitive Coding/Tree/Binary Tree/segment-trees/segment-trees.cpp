/*A c++ program for segment tree range query*/

#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define md 1000000007
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define all(c) (c).begin(),(c).end()
template< class T > T max2(const T &a,const T &b) {return (a < b ? b : a);}
template< class T > T min2(const T &a,const T &b) {return (a > b ? b : a);}
template< class T > T max3(const T &a, const T &b, const T &c) { return max2(a, max2(b, c)); }
template< class T > T min3(const T &a, const T &b, const T &c) { return min2(a, min2(b, c)); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(const T &a, const T &b) { return (a < b ? a : a % b); }
typedef pair<ll,ll> pi;
/*this program is designed for range sum type of query , this program can be also modified for the minimum of max query by changing the few command lines,
directions to where to make changes are given in the program, but please do not rely on them completely*/
class segmenttree
{
private:
    ll n;//size of the original array
    vector<ll> tree;
public:
    segmenttree(ll a[],ll size)
    {
        n=size;
        ll node=0;
        ll left=0;
        ll right=size-1;
        tree.assign(1000000,0);
            buildtree(a, node, left, right);

    }
    void buildtree(ll a[],int node,ll left,ll right)
    {
        if(left==right)
        {
            tree[node]=a[left];
        }
        else
        {
            ll mid=(left+right)/2;
            buildtree(a,2*node+1,left,mid);
            buildtree(a,2*node+2,mid+1,right);
            tree[node]=tree[2*node+1]+tree[2*node+2];//this tree is for the sum in the given range query , this line can be modified according to the need for
                                                    //example, if we have to find the minimum in the given range we can accordingly change the line of command;
        }

    }
    void updateutil(ll a[],ll x,ll pos,ll left,ll right,ll node)//give the val to be updated and the pos where to update. pos should be with respect to the original array.
    {
        if(left==right)
        {
            a[pos]=x;
            tree[node]=x;
        }
        else
        {
            ll mid=(left+right)/2;
            if(pos<=mid)
            {
                updateutil(a,x,pos,left,mid,2*node+1);
            }
            else
                updateutil(a,x,pos,mid+1,right,2*node+2);
            tree[node]=tree[2*node+1]+tree[2*node+2];//this line can be changed accordingly for a different query
        }
    }
    void update(ll a[],ll x,ll pos)
    {
        updateutil(a,x,pos-1,0,n-1,0);
    }
    void printtree()
    {
        for(ll i=0;i<2*n-1;i++)
            cout<<tree[i]<<endl;
    }
    ll queryutil(ll left,ll right,ll l,ll r,ll node)
    {

        if(left==l && right==r)
        {
            return tree[node];
        }
        else
        {
            if(left<=right)
            {
                ll mid=(l+r)/2;
                if(mid>=right)
                {
                    return queryutil(left,right,l,mid,2*node+1);
                }
                if(left>mid)
                {
                     return queryutil(left,right,mid+1,r,2*node+2);
                }
                if(left<=mid && right>mid)
                {
                    return queryutil(left,mid,l,mid,2*node+1)+queryutil(mid+1,right,mid+1,r,2*node+2);//this line can be changed for minimum or maximum query

                }
            }
            else
                return 0;

        }
    }
    ll query(ll left,ll right)
    {
        return queryutil(left-1,right-1,0,n-1,0);
    }

};
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    segmenttree segtree(a,n);
    segtree.printtree();
    /*
    segtree.update(a,7,5);//position here is the normal position that is , the counting starts from 1 and not from 0
    segtree.update(a,4,3);
    segtree.prlltree();*/
   // cout<<segtree.query(1,4);

}
