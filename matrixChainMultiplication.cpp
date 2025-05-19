#include<iostream>
using namespace std;

void printMatrix(int cost[][4], int dim)
{
    cout<<endl<<"***************************************"<<endl;
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<dim;j++)
        {
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"***************************************"<<endl;
}

void printOptimalParenthesis(int s[][4], int i, int j)
{
    if(i==j)
    {
        cout<<"M"<<i;
    }
    else
    {
        cout<<"(";
        printOptimalParenthesis(s,i,s[i][j]);
        printOptimalParenthesis(s,s[i][j]+1,j);
        cout<<")";
    }
}

int main()
{
    int n=4;
    //setting the dimensions for the four matrices
    int p[]={2,1,3,4};

    //initializing the m matrix and s matrix with zeros

    int cost[4][4]={0};
    int s[4][4]={0};
    int j=0;
    int min=0;
    int q=0;
    // d loop runs for the difference, initially 1 and then goes upto j-1
    for(int d=1;d<n;d++)
    {
        for(int i=1;i<n-d;i++)
        {
            j=i+d;
            min=INT_MAX;
            for(int k=i;k<j;k++)
            {
                q=cost[i][k]+cost[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(q<min)
                {
                    min=q;
                    s[i][j]=k;
                }
            }
            cost[i][j]=min;
        }
    }
    printMatrix(cost,n);
    printMatrix(s,n);

    //Now printing the resultant parenthesis using inorder traversal on s matrix
    cout<<endl<<"Optimal Parenthesis"<<endl;
    printOptimalParenthesis(s,1,n-1);
    cout<<endl;
}



