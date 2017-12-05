#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define infinite numeric_limits<int>::max()
#define Min(a,b)  ((a)<(b)?(a):(b))
#define Max(a,b)  ((a)>(b)?(a):(b))
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define ifr(i,j,s) for(i = j ; i >= s , i--)
void floydWasrshall(lli G[][400],int V)
{
    int u , v , w;
    fr(u,0,V)
    {
        fr(v,0,V)
        {
            fr(w,0,V)
            {
                if(G[v][u]+G[u][w] < G[v][w])
                    G[v][w] = G[v][u]+G[u][w] ;
            }
        }
    }
}
int main(void)
{
    int test,v,e,a,b,i,j;
    lli wt;
    cin>>v>>e;
    int ed = 0;
    lli graph[400][400];
    int temp = e ;
    fr(i,0,v)
    {
        fr(j,0,v)
        {
            graph[i][j] = infinite ;
            if(i==j)
                graph[i][j] = 0;
        }
    }
    while(e--)
    {
        cin>>a>>b>>wt;
        graph[a-1][b-1] = wt;
    }
    lli q ;
    cin>>q;
    floydWasrshall(graph,v);
    while(q--)
    {
        cin>>a>>b;
        if(graph[a-1][b-1] == infinite )
            graph[a-1][b-1] = -1 ;
        cout<<graph[a-1][b-1]<<endl;
    }
    return 0;
}
