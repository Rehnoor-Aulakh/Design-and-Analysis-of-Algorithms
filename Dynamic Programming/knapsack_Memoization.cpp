#include<iostream>
#include<vector>
using namespace std;

int solveMem(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int> >&dp)
{
	//Base Case: for one element only
	if(index==0)
	{
		if(weight[index]<=capacity)
		{
			return value[0];
		}
		else
		{
			return 0;
		}
	}

	if(dp[index][capacity]!=-1)
	{
		return dp[index][capacity];
	}

	int include=0;
	if(weight[index]<=capacity)
	{
		include=value[index]+solveMem(weight,value,index-1,capacity-weight[index],dp);
	}

	int exclude=solveMem(weight,value,index-1,capacity,dp);

	dp[index][capacity]=max(exclude,include);
	return dp[index][capacity];
}



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// return solve(weight,value,n-1,maxWeight);

	vector<vector<int> >dp(n,vector<int>(maxWeight+1,-1));
	return solveMem(weight,value,n-1,maxWeight,dp);
}

int main() {
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;
    cout << knapsack(weight, profit,profit.size(),W) << endl;
    return 0;
}