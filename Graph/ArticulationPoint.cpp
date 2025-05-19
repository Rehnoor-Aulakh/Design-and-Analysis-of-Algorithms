#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node, int parent, vector<int> &disc,vector<int> &low,unordered_map<int,bool> &visited ,unordered_map<int,list<int>> &adj, vector<int> &isArticulation, int timer)
{
    visited[node]=true;
    disc[node]=low[node]=timer++;
    int child=0;
    for(auto neighbor: adj[node])
    {
        if(neighbor==parent)
        {
            continue;
        }
        if(!visited[neighbor])
        {
            dfs(neighbor,node,disc,low,visited,adj,isArticulation,timer);
            low[node]=min(low[node],low[neighbor]);

            //check for articulation point
            if(low[neighbor]>=disc[node] && parent!=-1)
            {
                isArticulation[node]=1;
            }
            child++;
        }
        else
        {
            low[node]=min(low[node],disc[neighbor]);
        }
    }    
    //check for parent if -1 and child>1 then this is also AP
    if(parent == -1 && child>1)
    {
        isArticulation[node]=1;
    }
}

int main()
{
    int n=5;
    int e=5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(4,3));
    edges.push_back(make_pair(4,0));
    edges.push_back(make_pair(1,0));
    edges.push_back(make_pair(1,2));
    //creating  adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    int timer=0;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    unordered_map<int,bool> visited;
    vector<int> isArticulation(n,0);

    //dfs
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,-1,disc,low,visited,adj,isArticulation,timer);
        }
    }
    cout<<"Articulation Points are as follows: "<<endl;
    for(int i=0;i<n;i++)
    {
        if(isArticulation[i])
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;

}