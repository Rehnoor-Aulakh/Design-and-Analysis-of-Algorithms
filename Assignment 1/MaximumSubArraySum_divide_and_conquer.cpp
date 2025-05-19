#include<iostream>
using namespace std;

//Function to find the maximum crossing subarray sum
int maxCrossingSum(int arr[],int l, int m, int h)
{
    int sum=0;
    int left_sum=INT_MIN;
    for(int i=m;i>=l;i--)
    {
        sum+=arr[i];
        if(sum>left_sum)
        {
            left_sum=sum;
        }
    }
    sum=0;
    int right_sum=INT_MIN;
    for(int i=m+1;i<=h;i++)
    {
        sum+=arr[i];
        if(sum>right_sum)
        {
            right_sum=sum;
        }
    }
    return left_sum+right_sum;
}

//function to find the maximum subarray sum using divide and conquer
int maxSubArraySum(int arr[], int l, int h)
{
    //base case, single element
    if(l==h)
    {
        return arr[l];
    }
    int m=(l+h)/2;

    return max(max(maxSubArraySum(arr,l,m),maxSubArraySum(arr,m+1,h)),maxCrossingSum(arr,l,m,h));
}

int main()
{
    int arr[]= {-2, -5, 6, -2, -3, 1, 5, -6};
    int n=sizeof(arr)/sizeof(int);
    cout<<"Maximum Subarray sum is: "<<maxSubArraySum(arr,0,n-1)<<endl;

}