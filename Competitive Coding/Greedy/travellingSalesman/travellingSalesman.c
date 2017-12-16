#include <stdio.h>
#include<limits.h>
#include<math.h>
#define size 10 //maximum 10 cities
#define min(a,b) a>b?b:a
#define sizePOW 1024 // 2^10
int n,npow,g[size][sizePOW],p[size][sizePOW],adj[size][size];
int compute(int start,int set)
{	int masked,mask,result=INT_MAX,temp,i;
	if(g[start][set]!=-1)
		return g[start][set];
	for(i=0;i<n;i++)
	{
		mask=(npow-1)-(1<<i);
		masked=set&mask;
		if(masked!=set)
		{
			temp=adj[start][i]+compute(i,masked);
			if(temp<result)
				result=temp,p[start][set]=i;
		}
	}
	return g[start][set]=result;
}
void getpath(int start,int set)
{
	if(p[start][set]==-1) return;
	int x=p[start][set];
	int mask=(npow-1)-(1<<x);
	int masked=set&mask;
	printf("%d ",x);
	getpath(x,masked);
}
void TSP()
{	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<npow;j++)
			g[i][j]=p[i][j]=-1;
	for(i=0;i<n;i++)g[i][0]=adj[i][0];
	int result=compute(0,npow-2);
	printf("Tour cost:%d\n",result);
	printf("Tour path:\n0 ");
	getpath(0,npow-2);
	printf("0\n");
}
int main(void) {
	int i,j;
	printf("Enter number of cities\n");
	scanf("%d",&n);
	npow=(int)pow(2,n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&adj[i][j]);
	TSP();
	return 0;
}
