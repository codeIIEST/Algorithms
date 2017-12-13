#include<bits/stdc++.h>
using namespace std;

#define ll long long int
/*In this algorithm we use union and find method to find the existance of cycles in the graph. we have alocated a parent array , each node for a vertex. now
we write parent of that vertex in that node. first we do a find for root of the src and dest vertex of the edge which is to be checked weather it forms a
cycle or not, then we do the union of that two in a specific way if they have a different root. If the rank of a vertex is greater than the other than it becomes the parent of other
thid process decreaces the size of our tree. If the two vertex whose rooots are found have same root then it is clear that it will form a cycle hence we say that
we have found a cycle*/
typedef struct
{
    ll src;
    ll dest;
}edge;//This is the structure that saves the source and destination of each edge since it is a directed edge.
class Graph
{
private:
    ll vertex;
    ll edges;
    vector<edge> edgearray;
    vector<ll> parent;
    vector<ll> rank;
    list<ll> *array;
public:
    Graph(ll vertices=0,ll edge=0)//this constructor initialises the list for the vertices.The parent array and their rank.
    :vertex(vertices),edges(edge)
    {
        array= new list<ll>[vertex];
        parent.assign(vertex,-1);
        rank.assign(vertex,0);
    }
    ll find(ll v)//This returns the parent of the given vertex
    {
        if(parent[v]==-1)
            return v;
        else
            find(parent[v]);
    }
    void unions(ll x,ll y)//This unites two vertex
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
    ll iscycle(ll x,ll y)//This tells weather the given edge form a cycle of not
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
    Graph g(vertex,edges);
    for(ll i=0;i<edges;i++)
    {
        cin>>v1>>v2;
        g.addedge(v1,v2);
    }
}
