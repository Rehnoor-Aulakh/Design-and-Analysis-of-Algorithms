#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Generate all the possible subsets and return the one with the maximum profit

int knapsack(int W, vector<int> &wt,vector<int>& val,int n)
{
    //Base Case
    if(n==0 || W==0)
    {
        return 0;
    }

    //If the weight of current item is greater than the remaining weight, then it cannot be included
    if(wt[n-1]>W)
    {
        return knapsack(W,wt,val,n-1);
    }

    //Include/don't include
    return max(knapsack(W,wt,val,n-1),val[n-1]+knapsack(W-wt[n-1],wt,val,n-1));

}

int main()
{
    vector<int> profit = {60,100,120};
    vector<int> weight = {10,20,30};
    int W=50;
    cout<<knapsack(W,weight,profit,profit.size());

}