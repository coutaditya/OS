#include<bits/stdc++.h>
using namespace :: std;

class process{
    public:
        int id;
        int arrivalTime;
        int burstTime;
        int completionTime;
        int TAT;
        int WT;
        int RT;
};

void FCFS(vector<process> &v){
    int cur_time = 0;
    int id = 0;
    for(int i=0; i<v.size(); i++){
        if(cur_time<v[i].arrivalTime){
            cout<<"CPU idle from "<<cur_time<<" to "<<v[i].arrivalTime<<endl;
            cur_time = v[i].arrivalTime;
        }
        v[i].completionTime = cur_time+v[i].burstTime;
        v[i].RT = cur_time-v[i].arrivalTime;
        
        cout<<"Process P"<<v[i].id+1<<": start time = "<<cur_time<<" completion time = "<<v[i].completionTime<<endl;
        cur_time+=v[i].burstTime;
    }
}

int main(){

    cout<<"FIRST COME FIRST SERVE CPU SCHEDULING ALGORITHM C++ IMPLEMENTATION\n";
    cout<<"Name: Aditya Anand\tRoll No.:20124009\t Branch: IT\n\n\n";



    int n=0;
    cout<<"Enter the number of processes: ";
    cin>>n;

    if(n<=0){
        return 0;
    }

    cout<<"Enter the arrival times and burst times of "<<n<<" processes: \n";

    vector<process> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].arrivalTime>>v[i].burstTime;
        v[i].id = i;
    }

    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"\n";
    FCFS(v);
    cout<<"\n";
    cout<<"-------------------------------------------------------------------------------\n";
    cout<<"\n\n";

    int t_TAT=0;
    int t_CT=0;
    for(int i=0; i<n; i++){
        v[i].TAT = v[i].completionTime-v[i].arrivalTime;
        v[i].WT = v[i].TAT-v[i].burstTime;
        t_TAT+=v[i].TAT;
        t_CT+=v[i].completionTime;
    }

    for(auto p:v){
        cout<<"Process: "<<p.id<<"\tArrival Time:"<<p.arrivalTime<<"\tBurst Time:"<<p.burstTime<<"\tCompletion Time:"<<p.completionTime;
        cout<<"\tTurn Around Time:"<<p.TAT<<"\tWaiting Time:"<<p.WT<<"\tResponse Time:"<<p.RT<<"\n";
    }

    cout<<"\nAverage Turn Around Time: "<<(float)((1.0*t_TAT)/(1.0*n))<<"\n";
    cout<<"\nAverage Completion Time: "<<(float)((1.0*t_CT)/(1.0*n))<<"\n";

    return 0;
}