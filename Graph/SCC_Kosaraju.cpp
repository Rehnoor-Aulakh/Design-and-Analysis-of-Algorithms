#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int v, vector<vector<int> >&adj, vector<bool> &visited, stack<int> &st)
{
    visited[v]=true;
    for(auto u: adj[v])
    {
        if(!visited[u])
        {
            dfs(u,adj,visited,st);
        }
    }
    st.push(v);
}

void dfsUtil(int v, vector<vector<int> >&transpose, vector<bool> &visited)
{
    visited[v]=true;
    for(auto u: transpose[v])
    {
        if(!visited[u])
        {
            dfsUtil(u,transpose,visited);
        }
    }
}

int kosaraju(vector<vector<int> > &adj, int V)
{
    stack<int> st;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited,st);
        }
    }
    vector<vector<int> >transpose(V);
    for (int v = 0; v < V; v++)
        for (auto u : adj[v])
            transpose[u].push_back(v);

    fill(visited.begin(), visited.end(), false);
    int count = 0;

    //reverse dfs
    while(!st.empty())
    {
        int v=st.top();
        st.pop();
        if(!visited[v])
        {
            dfsUtil(v,transpose,visited);
            count++;
        }
    }
    return count;

}

int main()
{
    int V=5;
    vector<vector<int> >adj(V);
    adj[0].push_back(2);   
    adj[0].push_back(3);   
    adj[1].push_back(0);   
    adj[2].push_back(1);   
    adj[3].push_back(4);   

    cout<<kosaraju(adj,V)<<endl;

}