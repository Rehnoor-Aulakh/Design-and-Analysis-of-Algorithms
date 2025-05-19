#include<iostream>
using namespace std;

#define V 5

void printSolution(int path[])
{
    cout<<"Solution Exists"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<path[0]<<endl;
    
}

int isSafe(int v, int graph[V][V], int path[], int pos)
{
    //check that the vertex v should be adjacent to pos-1
    if(graph[path[pos-1]][v]==0)
    {
        return 0;
    }
    //check if the vertex has already been included
    for(int i=0;i<V;i++)
    {
        if(path[i]==v)
        {
            return 0;
        }
    }
    return 1;
}

int hamCycleUtil(int graph[V][V], int path[], int pos)
{
    //base case: if all the vertices are included
    if(pos==V)
    {
        //And if there is an edge from last included vertex to the first vertex
        if(graph[path[pos-1]][path[0]]==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    //try different vertices as candidate solutions
    //not trying for vertex 0 since it is starting node
    for(int v=1;v<V;v++)
    {
        //check if this vertex can be added
        if(isSafe(v,graph,path,pos))
        {
            path[pos]=v;
            //recur to construct the rest of the path
            if(hamCycleUtil(graph,path,pos+1)==1)
            {
                return 1;
            }
            path[pos]=-1;
        }
    }
    return 0;
}

int hamCycle(int graph[V][V])
{
    int path[V];
    for(int i=0;i<V;i++)
    {
        path[i]=-1;
    }
    //starting the path from vertex 0
    path[0]=0;
    //if there is any path, then we can loop from 0 to V for all the possibilities
    if(hamCycleUtil(graph,path,1)==0)
    {
        cout<<"Solution Does Not Exist"<<endl;
        return 0;
    }
    printSolution(path);
    return 1;

}

int main()
{
    int graph1[V][V]={{0,1,0,1,0},
    {1,0,1,1,1},
    {0,1,0,0,1},
    {1,1,0,0,1},
    {0,1,1,1,0}
    };

    hamCycle(graph1);

    // int graph2[V][V] = {{0, 1, 0, 1, 0},
    // {1, 0, 1, 1, 1},
    // {0, 1, 0, 0, 1},
    // {1, 1, 0, 0, 0},
    // {0, 1, 1, 0, 0},
    // };
    // hamCycle(graph2);

}