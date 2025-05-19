#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSquare(vector<vector<int> >&mat)
{
    //getting the number of rows and columns
    int n=mat.size();
    int m=mat[0].size();
    //creating a 2d matrix for tabulation
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int ans=0;
    //fill the dp
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(mat[i][j]==0)
            {
                dp[i][j]=0;
                continue;
            }

            dp[i][j]=1+min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int> >mat={{0, 1, 1, 0, 1}, 
    {1, 1, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0}};
    cout<<maxSquare(mat)<<endl;
}