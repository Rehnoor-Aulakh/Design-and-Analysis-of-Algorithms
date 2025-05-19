#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V = 6; // Number of vertices
    vector<vector<int> > adj(V); // Adjacency list

    // Given edges
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(3, 1));
    edges.push_back(make_pair(4, 0));
    edges.push_back(make_pair(4, 1));
    edges.push_back(make_pair(5, 0));
    edges.push_back(make_pair(5, 2));

    // Create the adjacency list
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    // Calculate in-degrees
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; ++u) {
        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j];
            indegree[v]++;
        }
    }

    // Enqueue all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Topological Sort
    vector<int> L;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        L.push_back(u);

        for (int j = 0; j < adj[u].size(); ++j) {
            int v = adj[u][j];
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Print the topological order
    cout << "Topological Order: ";
    for (int i = 0; i < L.size(); ++i) {
        cout << L[i] << " ";
    }
    cout << endl;

    return 0;
}
