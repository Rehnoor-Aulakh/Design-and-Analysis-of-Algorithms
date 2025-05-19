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
    vector<vector<int> >dp(n+1,vector<int>(m+1,0));
    int ans=0;
    //fill the dp

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+1;
                ans=max(ans,dp[i][j]);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int> > mat;

    vector<int> row1;
    row1.push_back(0); row1.push_back(1); row1.push_back(1); row1.push_back(0); row1.push_back(1);
    mat.push_back(row1);

    vector<int> row2;
    row2.push_back(1); row2.push_back(1); row2.push_back(0); row2.push_back(1); row2.push_back(0);
    mat.push_back(row2);

    vector<int> row3;
    row3.push_back(0); row3.push_back(1); row3.push_back(1); row3.push_back(1); row3.push_back(0);
    mat.push_back(row3);

    vector<int> row4;
    row4.push_back(1); row4.push_back(1); row4.push_back(1); row4.push_back(1); row4.push_back(0);
    mat.push_back(row4);

    vector<int> row5;
    row5.push_back(1); row5.push_back(1); row5.push_back(1); row5.push_back(1); row5.push_back(1);
    mat.push_back(row5);

    vector<int> row6;
    row6.push_back(0); row6.push_back(0); row6.push_back(0); row6.push_back(0); row6.push_back(0);
    mat.push_back(row6);
    cout<<maxSquare(mat)<<endl;
}

