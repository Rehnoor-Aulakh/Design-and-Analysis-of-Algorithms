#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Job
{
    private:
    char jobId;

    public:
    int deadline;
    int profit;
    Job()
    {

    }
    Job(char jobId, int deadline, int profit)
    {
        this->jobId=jobId;
        this->deadline=deadline;
        this->profit=profit;
    }

    void display()
    {
        cout<<"JobID: "<<jobId<<endl;
        cout<<"Deadline: "<<deadline<<endl;
        cout<<"Profit: "<<profit<<endl;
    }
};


bool compare(const Job &j1, const Job &j2)
{
    return j1.profit>j2.profit;
}

vector<Job> run(vector<Job> job)
{
    sort(job.begin(),job.end(),compare);
    vector<Job> sol;
    sol.push_back(job[0]);
    //find the size of gantt chart
    int size=0;
    for(int i=0;i<job.size();i++)
    {
        if(job[i].deadline>size)
        {
            size=job[i].deadline;
        }
    }
    //make an int array of size to store the values of profit
    int gantt[size];
    bool isFilled[size];
    for(int i=0;i<size;i++)
    {
        isFilled[i]=false;
    }
    //maximum profit add to gantt chart 
    //find the position of job[0] in the gantt chart i.e the deadline
    //deadline-1 will be the position
    gantt[job[0].deadline-1]=job[0].profit;
    isFilled[job[0].deadline-1]=true;
    for(int i=1;i<job.size();i++)
    {
        // add job[i] to the gantt chart if space is available
        //first try in the desired position if available
        if(!isFilled[job[i].deadline-1])
        {
            sol.push_back(job[i]);
            isFilled[job[i].deadline-1];
        }
        else
        {
            for(int j=job[i].deadline-1;j>=0;j--)
            {
                if(!isFilled[j])
                {
                    sol.push_back(job[i]);
                    isFilled[j]=true;
                    break;
                }
            }
        }
        
    }

    return sol;
}

int main()
{
    Job job[]={Job('a',4,20),Job('b',1,10),Job('c',1,40),Job('d',1,30)};
    vector<Job> j;
    for(int i=0;i<sizeof(job)/sizeof(Job);i++)
    {
        j.push_back(job[i]);
    }

    vector<Job> sol=run(j);
    int profit=0;
    for(int i=0;i<sol.size();i++)
    {
        sol[i].display();
        profit+=sol[i].profit;

    }
    cout<<profit<<endl;
}