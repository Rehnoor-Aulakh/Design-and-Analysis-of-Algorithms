#include<iostream>
using namespace std;

int BinarySearch(int arr[], int num, int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==num)
        {
            return mid;
        }
        else if(arr[mid]<num)
        {
            //go right
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        return BinarySearch(arr,num,low,high);
    }
    else
    {
        return -1;
    }
}

int main()
{
    int num;
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    cout<<"Enter Number to find in array: ";
    cin>>num;
    int res=BinarySearch(arr,num,0,sizeof(arr)/sizeof(int));
    if(res==-1)
    {
        cout<<"Number not found"<<endl;
    }    
    else
    {
        cout<<"Number found at index "<<res<<endl;
    }
}