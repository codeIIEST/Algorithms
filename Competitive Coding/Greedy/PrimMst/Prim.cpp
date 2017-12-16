#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
// declare a class for graph

struct Edge{
	int src,dest,weight;
};

class Graph{
	int V,E;
	vector<Edge> edge;  // an array of all the edges
	public:
	Graph(int v, int e);
	void addEdge(int src, int dest, int weight);
	void mst();
};

Graph::Graph(int v, int e){
	V=v;
	E=e;
}

void Graph::addEdge(int src, int dest, int weight){
	Edge *e= new Edge;
	e->src= src;
	e->dest= dest;
	e->weight= weight;
	edge.push_back(*e);
}
bool comp(Edge e1, Edge e2){
	return e1.weight<e2.weight ;
}

struct subset{
	int parent;
	int rank;
};
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i){
	// find root and make root as parent of i (path compression)
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	// Attach smaller rank tree under root of high rank tree
	// (Union by Rank)
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

void Graph::mst(){
	sort(edge.begin(), edge.end(), comp);
	//create disjoint set for all vertices
	struct subset *subsets = new subset[V];

	// Create V subsets with single elements
	for(int i=0;i<V;i++){
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	vector<Edge> result;

	// Number of edges to be taken is equal to V-1
	for(auto i=edge.begin(); i!=edge.end();i++){
		int src= i->src;
		int dest=i->dest;
		//if not same root
		if(find(subsets, src)!= find(subsets, dest)){
			result.push_back(*i);
			Union(subsets, src, dest);
		}
	}
	printf("The edges of the MST are\n");
	for(auto i=result.begin(); i!=result.end(); i++)
		cout<<i->src<<"--"<<i->dest<<"="<<i->weight<<endl;
	return;
}

int main(){
	int V;  // Number of vertices in graph
	int E;
	printf("Enter no of vertices and edges\n");
	scanf("%d%d",&V,&E); // Number of edges in graph
	Graph g(V,E);
	int i,u,v,x;
	printf("Enter\nsrc dest weight\n");
	for(i=0;i<E;i++)
	{
		scanf("%d%d%d",&u,&v,&x);
		g.addEdge(u,v,x);
	}
	// add edge 0-1
	/*g.addEdge(0,3,1);
	g.addEdge(4,5,2);
	g.addEdge(2,4,5);
	g.addEdge(3,4,6);
	g.addEdge(0,1,3);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(1,3,3);
	g.addEdge(2,5,4);*/
	g.mst();
}
