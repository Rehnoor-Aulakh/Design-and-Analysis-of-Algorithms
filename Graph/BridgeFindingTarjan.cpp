#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int>& disc, vector<int>& low, 
         vector<vector<int>>& result, unordered_map<int,list<int>>& adj, 
         unordered_map<int,bool>& visited) 
{
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neighbor: adj[node]) 
    {
        if(neighbor == parent)
            continue;

        if(!visited[neighbor]) 
        {
            dfs(neighbor, node, timer, disc, low, result, adj, visited);
            low[node] = min(low[node], low[neighbor]);

            // If the subtree rooted at neighbor has no back connection
            if(low[neighbor] > disc[node]) 
                result.push_back({node, neighbor});
        }
        else 
        {
            // Back edge
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) 
{
    unordered_map<int,list<int>> adj;

    for(int i = 0; i < edges.size(); i++) 
    {
        int u = edges[i][0];
        int vertex = edges[i][1];
        adj[u].push_back(vertex);
        adj[vertex].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int,bool> visited;
    vector<vector<int>> result;

    for(int i = 0; i < v; i++) 
    {
        if(!visited[i]) 
            dfs(i, -1, timer, disc, low, result, adj, visited);
    }

    return result;
}

int main() 
{
    int v = 5, e = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "Bridges in the graph:\n";
    for(auto& bridge : bridges) 
    {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
