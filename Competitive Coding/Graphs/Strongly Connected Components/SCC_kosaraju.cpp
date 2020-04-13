// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
void dfs1(vector<int> adj[],stack<int>& st,int s,bool* vis){
    vis[s]=true;
    for(auto j:adj[s]){
        if(!vis[j]){
            dfs1(adj,st,j,vis);
        }
    }
    st.push(s);
}
void dfs2(vector<int> adj[],int s,bool* vis){
    vis[s]=true;
    for(auto j:adj[s]){
        if(!vis[j]){
            dfs2(adj,j,vis);
        }
    }
}

int kosaraju(int V, vector<int> adj[]){
    // Your code here
    bool vis[V];
    for(int i=0;i<V;i++) vis[i]=false;
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs1(adj,st,i,vis);
        }
    }
    vector<int> newg[V];
    for(int i=0;i<V;i++){
        vector<int> v;
        newg[i]=v;
    }
    for(int i=0;i<V;i++){
        for(auto j: adj[i]){
            newg[j].push_back(i);
        }
    }
    for(int i=0;i<V;i++) vis[i]=false;
    int ans=0;
    while(!st.empty()){
        int t=st.top();
        st.pop();
        if(!vis[t]){
            ans++;
            dfs2(newg,t,vis);
        }
    }
    return ans;
}


// { Driver Code Starts.

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}  // } Driver Code Ends