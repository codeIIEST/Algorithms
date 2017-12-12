#include<bits/stdc++.h>
using namespace std;

struct Edge
{
	int src,dest,weight;
};

struct Graph
{
	int V,E;
	struct Edge* edge;
};

struct Graph* buildGraph(int V,int E)
{
	struct Graph* graph=new Graph;
	graph->V=V;
	graph->E=E;
	graph->edge=new Edge[E];
	return graph;
}

void PrintSoln(int dist[],int n)
{
	cout<<"Vertex  Distance from source\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<i<<"\t"<<dist[i]<<"\n";
	}
}

void BellmanFord(struct Graph* graph,int src)
{
	int V=graph->V;
	int E=graph->E;
	int dist[V];

	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
	}
	dist[src]=0;

	for(int i=1;i<=(V-1);i++)
	{
		for(int j=0;j<E;j++)
		{
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			int weight=graph->edge[j].weight;
			if(dist[u]!=INT_MAX && (dist[u]+weight<dist[v]))
			{
				dist[v]=dist[u]+weight;
			}
		}
	}

	for(int i=0;i<E;i++)
	{
		int u=graph->edge[i].src;
		int v=graph->edge[i].dest;
		int weight=graph->edge[i].weight;
		if(dist[u]!=INT_MAX && (dist[u] + weight < dist[v]))
			cout<<"Graph contains negative weight cycle\n";
	}
	PrintSoln(dist,V);
}

int main()
{
	int V = 5;  // Number of vertices in graph
    int E = 8;  // Number of edges in graph
    struct Graph* graph = buildGraph(V, E);
 
    // add edge 0-1 
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
 
    // add edge 0-2 
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
 
    // add edge 1-2
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
 
    // add edge 1-3 
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
 
    // add edge 1-4
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
 
    // add edge 3-2 
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
 
    // add edge 3-1 
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
 
    // add edge 4-3
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
 
    BellmanFord(graph, 0);
 
    return 0;
}
