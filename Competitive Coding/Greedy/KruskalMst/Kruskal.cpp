#include<bits/stdc++.h>
using namespace std;
bool vis[100];
int arr[100],size[100];
#define piii pair<int,pair<int,int> >
class mycmp{
	public:
		bool operator()(piii p1,piii p2)
		{
			return p1.first>p2.first;
		}
};
int root(int x)
{
	while(arr[x]!=x)
	{
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
	return x;
}
bool find(int x,int y)
{
	int rootx=root(x),rooty=root(y);
	return rootx==rooty;
}
void union1(int x,int y)
{
	int rootx=root(x);
	int rooty=root(y);
	if(size[rootx]<size[rooty])
	{
		arr[rootx]=rooty;
		size[rooty]+=size[rootx];
	}
	else
	{
		arr[rooty]=rootx;
		size[rootx]+=size[rooty];
	}
}
int main()
{
	printf("Enter no of vertices and no of edges\n");
	int n,m,i;cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		arr[i]=i;
		size[i]=1;
	}
	printf("Enter\nsrc dest weight\n");
	priority_queue<piii,vector<piii>,mycmp>pq;
	for(i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		pq.push({w,{u,v}});
	}
	int sum=0;
	while(!pq.empty())
	{
		piii p=pq.top();
		pq.pop();
		int w=p.first,fir=p.second.first,sec=p.second.second;
		if(find(fir,sec)==false)
		{
			sum+=w;
			union1(fir,sec);
		}
	}
	printf("weight of MST\n");
	cout<<sum<<endl;
}
