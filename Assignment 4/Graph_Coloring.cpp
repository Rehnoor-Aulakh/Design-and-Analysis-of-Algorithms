#include<iostream>
#include<vector>
using namespace std;
bool found=false;
bool isSafe(vector<vector<int> >&graph, vector<int> &colors, int k, int c)
{
    for(int i=0;i<graph.size();i++)
    {
        if(graph[k][i]==1 && colors[i]==c)
        {
            return false;
        }   
    }
    return true;
}

//maximum m colors, k is the current color
void graphColor(vector<vector<int> >&graph, int k, int m, vector<int> &colors)
{
    if(found)
    {
        return;
    }
    int n=graph.size();
    if(k==n)
    {
        found=true;
        cout<<"Solution: "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<colors[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //try all the colors 
    for(int c=1;c<=m;c++)
    {
        if(isSafe(graph,colors,k,c))
        {
            colors[k]=c;
            graphColor(graph,k+1,m,colors);
            colors[k]=0; //Backtrack
        }
    }
}

int main()
{
    vector<vector<int> > graph(4);

    graph[0].push_back(0);
    graph[0].push_back(1);
    graph[0].push_back(1);
    graph[0].push_back(1);

    graph[1].push_back(1);
    graph[1].push_back(0);
    graph[1].push_back(1);
    graph[1].push_back(0);

    graph[2].push_back(1);
    graph[2].push_back(1);
    graph[2].push_back(0);
    graph[2].push_back(1);

    graph[3].push_back(1);
    graph[3].push_back(0);
    graph[3].push_back(1);
    graph[3].push_back(0);
    int n=graph.size();
    vector<int> colors(n,0);
    graphColor(graph,0,4,colors);
}