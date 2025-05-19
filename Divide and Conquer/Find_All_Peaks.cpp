#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void binary_search(vector<int>& answer, vector<int> mountain, int left, int right)
    {
        if(left<=right)
        {
            int mid=(left+right)/2;
            if(mountain[mid]>mountain[mid+1] && mountain[mid]>mountain[mid-1])
            {
                answer.push_back(mid);
            }
            binary_search(answer,mountain, left, mid-1);
            binary_search(answer,mountain,mid+1,right);
        }
    }

    vector<int> findPeaks(vector<int>& mountain) 
    {
        vector<int> answer;
        binary_search(answer,mountain,1,mountain.size()-2);
        return answer;
    }
};