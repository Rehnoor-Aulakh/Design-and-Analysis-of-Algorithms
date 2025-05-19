#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Activity
{
    
    public:
    int start;
    int finish;
    Activity(){
        start=0;
        finish=0;
    }
    Activity(int start, int finish)
    {
        this->finish=finish;
        this->start=start;
    }
    void display()
    {
        cout<<"Start: "<<start<<endl;
        cout<<"Finish: "<<finish<<endl;
    }
};

bool activityCompare(const Activity &a1, const Activity &a2) {
    return a1.finish < a2.finish;
}

vector<Activity> run(vector<Activity> &act)
{

    sort(act.begin(),act.end(),activityCompare);
    int finish=act[0].finish;
    vector<Activity> sol;
    sol.push_back(act[0]);
    for(int i=1;i<act.size();i++)
    {
        if(act[i].start>=finish)
        {
            sol.push_back(act[i]);
            finish=act[i].finish;
        }
    }
    return sol;
}

int main()
{
    Activity act[]={Activity(1,2),Activity(3,4),Activity(0,6),Activity(5,7),Activity(8,9),Activity(5,9)};
    //First one will run as it is
    vector<Activity> act2;
    for(int i=0;i<sizeof(act)/sizeof(Activity);i++)
    {
        act2.push_back(act[i]);
    }
    vector<Activity> sol=run(act2);

    for(int i=0;i<sol.size();i++)
    {
        sol[i].display();
    }
    cout<<"Activities ran are "<<sol.size()<<endl;

}