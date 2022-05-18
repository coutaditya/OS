#include <bits/stdc++.h>
using namespace ::std;

class process{
    public:
        int priority;
        int id;
        int arrivalTime;
        int burstTime;
        bool ready;
        int completionTime;
        int TAT;
        int WT;
        int RT;
};

// sorts the process according to increasing priority
struct comp{
    bool operator()(process const &p1, process const &p2){
        return p1.priority < p2.priority;
    }
};

void PriorityBasedScheduling(vector<process> &v){
    priority_queue<process, vector<process>, comp> p;
    int cur_time = INT_MAX;
    int n=v.size();
    for(int i=0; i<n; i++){
        cur_time = min(cur_time, v[i].arrivalTime);
    }
    
    int count = 0;
    while(true){
        for(int i=0; i<n; i++){
            if(v[i].arrivalTime<=cur_time && !v[i].ready){
                v[i].ready = true;
                p.push(v[i]);
                count++;
            }
        }
        if(count<n && p.empty()){
            cout<<"CPU empty from "<<cur_time<<" to "<<cur_time+1<<"\n";
            cur_time++;
            continue;
        }

        if(p.empty()){
            break;
        }

        process cur_process = p.top();
        p.pop();

        v[cur_process.id].RT = cur_time-cur_process.arrivalTime;
        cur_time+=cur_process.burstTime;
        v[cur_process.id].completionTime=cur_time;
    }
}

int main(){

    cout << "PRIORITY BASED CPU SCHEDULING ALGORITHM C++ IMPLEMENTATION\n";
    cout << "Name: Aditya Anand\tRoll No.:20124009\t Branch: IT\n\n\n";

    int n = 0;
    cout << "Enter the number of processes: ";
    cin >> n;

    if(n<=0){
        return 0;
    }

    cout << "Enter the arrival times and burst times and priority values of " << n << " processes: \n";

    
    vector<process> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].arrivalTime >> v[i].burstTime >> v[i].priority;
        v[i].ready = false;
        v[i].id = i;
    }

    cout << "-------------------------------------------------------------------------------\n";
    cout << "\n";
    PriorityBasedScheduling(v);
    cout << "\n";
    cout << "-------------------------------------------------------------------------------\n";
    cout << "\n\n";

    int t_TAT = 0;
    int t_CT = 0;
    for (int i = 0; i < n; i++){
        v[i].TAT = v[i].completionTime - v[i].arrivalTime;
        v[i].WT = v[i].TAT - v[i].burstTime;
        t_TAT += v[i].TAT;
        t_CT += v[i].completionTime;
    }

    for (auto p : v){
        cout << "Process: " << p.id << "\tArrival Time:" << p.arrivalTime << "\tBurst Time:" << p.burstTime << "\tCompletion Time:" << p.completionTime;
        cout << "\tTurn Around Time:" << p.TAT << "\tWaiting Time:" << p.WT << "\tResponse Time:" << p.RT << "\n";
    }

    cout << "\nAverage Turn Around Time: " << (float)((1.0 * t_TAT) / (1.0 * n)) << "\n";
    cout << "\nAverage Completion Time: " << (float)((1.0 * t_CT) / (1.0 * n)) << "\n";

    return 0;
}