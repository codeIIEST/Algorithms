#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define infinite 0xffff
#define Min(a,b)  ((a)<(b)?(a):(b))
#define Max(a,b)  ((a)>(b)?(a):(b))
#define fr(i,j,s) for(i = j ; i < s ; i++)
#define ifr(i,j,s) for(i = j ; i >= s , i--)
struct adjListNode
{
    int dest;
    int wt;
    struct adjListNode *next;
};
struct adjList
{
    struct adjListNode *head;
};
struct Graph
{
    int V ; 
    struct adjList *array;
};
struct adjListNode * newAdjNode(int dest, int wt)
{
    struct adjListNode *newNode = (struct adjListNode* )malloc(sizeof(struct adjListNode));
    newNode->dest = dest;
    newNode->wt = wt;
    newNode->next  = NULL ;
    return newNode;   
}
struct Graph* createGraph(int V,int E)
{
    int i ;
    struct Graph* G = (struct Graph *)malloc(sizeof(struct Graph));
    G->V = V ; 
    G->array = (struct adjList*)malloc(E*sizeof(struct adjList));
    fr(i,0,V)
    {
        G->array[i].head = NULL ;
    }
    return G ;
}
void addEdge(struct Graph *G,int src, int dest, int wt)
{
    struct adjListNode*temp=newAdjNode(dest,wt);
    temp->next=G->array[src].head;
    G->array[src].head=temp;

    temp=newAdjNode(src,wt);
    temp->next=G->array[dest].head;
    G->array[dest].head=temp;
}
struct MinHeapNode
{
    int  v;
    int dist;
};
struct MinHeap
{
    int size;      
    int capacity;  
    int *pos;     
    struct MinHeapNode **array;
};
struct MinHeapNode* newMinHeapNode(int v, int dist)
{
    struct MinHeapNode* minHeapNode =
           (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
         (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist )
      smallest = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist )
      smallest = right;
 
    if (smallest != idx)
    {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];
 
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
 
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
 
        minHeapify(minHeap, smallest);
    }
}
 
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}
 
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
 
    struct MinHeapNode* root = minHeap->array[0];
 
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
 
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
 
    --minHeap->size;
    minHeapify(minHeap, 0);
 
    return root;
}
 
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
    int i = minHeap->pos[v];
 
    minHeap->array[i]->dist = dist;
 
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
 
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
   if (minHeap->pos[v] < minHeap->size)
     return true;
   return false;
}
void printarr(int dist[], int v , int src)
{
    int i ;
    fr(i,0,v)
    {
        if(i==src)
            continue;
        if(dist[i] == infinite)
            dist[i] = -1 ;
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
void dijsktra(struct Graph*G,int src)
{
    int i,j;
    int V = G->V;
    int dist[V];
    struct MinHeap * minHeap = createMinHeap(V);
    fr(i,0,V)
    {   
        dist[i] = infinite ;
        minHeap->array[i] = newMinHeapNode(i,dist[i]);
        minHeap->pos[i] = i ; 
    }   
    minHeap->array[src] = newMinHeapNode(src,dist[src]) ;
    minHeap->pos[src] = src ;
    dist[src] = 0 ;
    decreaseKey(minHeap,src,dist[src]);
    minHeap->size = V ;
    while(!isEmpty(minHeap))
    {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        struct adjListNode* pCrawl = G->array[u].head;
        while (pCrawl != NULL)
        {
            int v = pCrawl->dest;
            if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->wt + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->wt;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    printarr(dist,V,src);
}
int main(void)
{
    int test,v,e,a,b,wt;
    cin>>test;
    while(test--)
    {
        cin>>v>>e;
        struct Graph* G = createGraph(v,e);
        while(e--)
        {
            cin>>a>>b>>wt;
            addEdge(G,a-1,b-1,wt);
        }
        cin>>a;
        dijsktra(G,a-1);
    }        
    return 0;
}
