#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define infinite numeric_limits<int>::max()
#define Min(a,b)  ((a)<(b)?(a):(b))
#define Max(a,b)  ((a)>(b)?(a):(b))
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define ifr(i,j,s) for(i = j ; i >= s , i--)
struct edge
{
    lli wt;
    int src; 
    int dest;
};
struct Graph
{
    int V;
    int E;
    struct edge* array;
};
struct sub
{
    int parent;
    int rank;
};
bool comp(struct edge &a, struct edge &b)
{
    return ((a.wt)<(b.wt));
}
int find(struct sub subset[], int i)
{
    if(subset[i].parent != i)
    {
        subset[i].parent = find(subset,subset[i].parent);
    }
    return subset[i].parent ;
}
void Union(struct sub subset[] , int x, int y)
{
    int xfather = find(subset,x);
    int yfather = find(subset,y);
    if(subset[xfather].rank<subset[yfather].rank)
        subset[xfather].parent = yfather ;
    else if(subset[yfather].rank<subset[xfather].rank)
        subset[yfather].parent = xfather ;
    else
    {
        subset[yfather].parent = xfather;
        subset[xfather].rank++; 
    }
}
struct Graph* createGraph(int V,int E)
{
    int i ;
    struct Graph* G = (struct Graph *)malloc(sizeof(struct Graph));
    G->V = V ;
    G->E = E ; 
    G->array = (struct edge*)malloc(E*sizeof(struct edge));
    return G ;
}
void KruskalMST(struct Graph *G)
{
    int i ;
    int V = G->V ;
    int E = G->E ;
    lli sum  = 0 ;
    struct sub subset[G->V];
    fr(i,0,V)
    {
        subset[i].parent = i ;
        subset[i].rank = 0 ;
    }
    sort(G->array, (G->array)+G->E,comp);
    fr(i,0,E)
    {
        int x = find(subset,G->array[i].src);
        int y = find(subset,G->array[i].dest);
        if(x==y)
            continue;
        else
        {
            Union(subset,G->array[i].src,G->array[i].dest);
            sum+=G->array[i].wt;
        }
    }
    cout<<sum<<endl;
}
int main(void)
{
    int test,v,e,a,b;
    lli wt;
    cin>>v>>e;
    struct Graph* G = createGraph(v,e);
    int ed = 0;
    int temp = e ;
    while(e--)
    {
        cin>>a>>b>>wt;
        G->array[ed].src=a-1;
        G->array[ed].dest=b-1;
        G->array[ed].wt=wt;
        ed++;
    }
    cin>>a;
    KruskalMST(G);
    return 0;
}
