#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    
    static bool cmp(pair<int,int> a, pair<int,int>b)
    {
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& finish) 
    {
        vector<pair<int,int> >v;
        for(int i=0;i<start.size();i++)
        {
            pair<int,int> p=make_pair(start[i],finish[i]);
            v.push_back(p);
        }
        
        //sort the vector on the basis of start and finish time
        sort(v.begin(),v.end(),cmp);
        //once the array is sorted calculate which meetings can take place
        int meetings=1;
        int finish_time=v[0].second;
        for(int i=1;i<start.size();i++)
        {
            if(v[i].first>=finish_time)
            {
                meetings++;
                finish_time=v[i].second;
            }
        }
        
        return meetings;
    }
};