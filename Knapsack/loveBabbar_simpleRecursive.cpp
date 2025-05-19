#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> weight, vector<int> value, int index, int capacity)
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

	int include=0;
	if(weight[index]<=capacity)
	{
		include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
	}

	int exclude=solve(weight,value,index-1,capacity);

	return max(exclude,include);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solve(weight,value,n-1,maxWeight);
}