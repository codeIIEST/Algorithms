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
/*In this algorithm we use union and find method to find the existance of cycles in the graph. we have alocated a parent array , each node for a vertex. now
we write parent of that vertex in that node. first we do a find for root of the src and dest vertex of the edge which is to be checked weather it forms a
cycle or not, then we do the union of that two in a specific way if they have a different root. If the rank of a vertex is greater than the other than it becomes the parent of other
thid process decreaces the size of our tree. If the two vertex whose rooots are found have same root then it is clear that it will form a cycle hence we say that
we have found a cycle*/
typedef struct
{
    ll src;
    ll dest;
}edge;
class graph
{
private:
    ll vertex;
    ll edges;
    vector<edge> edgearray;
    vector<ll> parent;
    vector<ll> rank;
    list<ll> *array;
public:
    graph()
    {
        vertex=0;
        edges=0;
    }
    graph(ll vertices=0,ll edge=0)
    :vertex(vertices),edges(edge)
    {
        array= new list<ll>[vertex];
        parent.assign(vertex,-1);
        rank.assign(vertex,0);
    }
    ll find(ll v)
    {
        if(parent[v]==-1)
            return v;
        else
            find(parent[v]);
    }
    void unions(ll x,ll y)
    {
        ll xroot=find(x);
        ll yroot=find(y);
        if(rank[xroot]>rank[yroot])
            parent[yroot]=xroot;
        else
            if(rank[yroot]>rank[xroot])
            parent[xroot]=yroot;
        else
        {
            parent[xroot]=yroot;
            rank[yroot]++;
        }
    }
    ll iscycle(ll x,ll y)
    {

        ll xroot=find(x);
        ll yroot=find(y);
        if(xroot==yroot)
            return 1;
        else
        {
            unions(x,y);
            return 0;
        }
    }
    void addedge(ll v1,ll v2)
    {
        array[v1].push_back(v2);
        array[v2].push_back(v1);
        edge temp;
        temp.src=v1;
        temp.dest=v2;
        edgearray.push_back(temp);
    }

};
int main()
{
    ll vertex;ll edges,v1,v2;
    cin>>vertex>>edges;
    graph g(vertex,edges);
    for(ll i=0;i<edges;i++)
    {
        cin>>v1>>v2;
        g.addedge(v1,v2);
    }

}
