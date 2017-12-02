#include<bits/stdc++.h>
using namespace std;

vector<bool>Visited;
vector< vector<int> >Graph;

void edge(int a,int b)
{
	Graph[a].push_back(b); //for directed

	//If undirected graph is there, then add the following line
	// Graph[b].push_back(a);
}

void BreadthFirstSearch(int u)
{
	queue<int>q;
	q.push(u);
	Visited[u]=true;

	while(!q.empty())
	{
		int f=q.front();
		q.pop();

		cout<<f<<" ";
		int ln=Graph[f].size();
		for(int j=0;j<ln;j++)
		{
			if(!Visited[Graph[f][j]])
			{
				q.push(Graph[f][j]);
				Visited[Graph[f][j]]=true;
			}
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	Visited.assign(n,false);
	Graph.assign(n,vector<int>());

	int a,b;
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		edge(a,b);
	}

	for(int i=0;i<n;i++)
	{
		if(!Visited[i])
		{
			BreadthFirstSearch(i);
		}
	}
	return 0;
}