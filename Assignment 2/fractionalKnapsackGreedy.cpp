#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(vector<int>& a, vector<int> &b)
{
    double r1=(double)a[0]/a[1];
    double r2=(double)b[0]/b[1];
    return r1>r2; 
}

int maxProfit(vector<vector<int> >arr, int W)
{
    //Sort these items according to profit-to-weight ratios
    sort(arr.begin(),arr.end(),compare);

    //Getting the number of items
    int n=arr.size();
    int currWeight=0;
    double finalProfit=0;

    for(int i=0;i<n;i++)
    {
        //If the item's weight can be fully accomplished
        if(currWeight+arr[i][1]<=W)
        {
            currWeight+=arr[i][1];
            finalProfit+=arr[i][0];
        }
        else
        {
            //Get the fraction of the next item that can be accomplished
            int remaining=W-currWeight;
            finalProfit+=arr[i][0]*((double)remaining/arr[i][1]);
            break;
        }
    }
    return finalProfit;
}

int main()
{
    // {Profit,Weight}
    int W=50;
    vector<vector<int> >arr;
    arr.push_back(vector<int>(2));
    arr[0][0] = 60;
    arr[0][1] = 10;
    arr.push_back(vector<int>(2));
    arr[1][0] = 100;
    arr[1][1] = 20;
    arr.push_back(vector<int>(2));
    arr[2][0] = 120;
    arr[2][1] = 30;
    cout<<"Maximum Profit is: "<<maxProfit(arr,W)<<endl;

}