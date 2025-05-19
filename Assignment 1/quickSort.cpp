#include<iostream>
using namespace std;

void quickSort(int arr[],int L,int U)
{
    if(L<U)
    {
        int pivot=U;
        int i=L-1;
        // O(N) time for partition algorithm
        for(int j=L;j<U;j++)
        {
            if(arr[j]<=arr[pivot])
            {
                i++;
                //swap arr[i] with arr[j]
                int t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
        //swap pivot with i+1 position
        int t=arr[i+1];
        arr[i+1]=arr[pivot];
        arr[pivot]=t;

        //now recursive calls for quick sort O(logN) time because dividing into half
        quickSort(arr,L,i);
        quickSort(arr,i+2,U);
    }
}

int main()
{
    int arr[]={ 4, 2, 6, 9, 2 };
    quickSort(arr,0,sizeof(arr)/sizeof(int)-1);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}