// C++ implementation of Banker's deadlock avoidance and prevention algorithm
#include <bits/stdc++.h>
using namespace ::std;

// Class representing state of the system: how various resources are allocated and requested by various processes
struct state
{
    long long int resources, processes;
    vector<vector<long long int>> allocated;
    vector<vector<long long int>> max_req;
    vector<vector<long long int>> remaining_req;
    vector<long long int> available;
    vector<bool> executed;

    state(long long int res, long long int pro)
    {
        this->resources = res;
        this->processes = pro;

        allocated.resize(pro, vector<long long int>(res, 0));
        max_req.resize(pro, vector<long long int>(res, 0));
        remaining_req.resize(pro, vector<long long int>(res, 0));
        available.resize(res, 0);
        executed.resize(pro, false);
        cout << "executed";
    }
};

queue<long long int> safe_seq;

bool bankers(state s)
{
    long long int n = s.processes;
    while (n--)
    {
        cout << "Current availability: ";
        for (long long int i = 0; i < s.resources; i++)
        {
            cout << s.available[i] << " ";
        }
        cout << "\n";

        bool found = false;
        for (long long int i = 0; i < s.processes; i++)
        {
            bool t = true;
            if (!s.executed[i])
            {
                for (long long int j = 0; j < s.resources; j++)
                {
                    if (s.available[j] < s.remaining_req[i][j])
                    {
                        t = false;
                        break;
                    }
                }
                if (t)
                {
                    found = true;
                    safe_seq.push(i + 1);
                    s.executed[i] = true;
                    cout << "P" << i + 1 << " has been allocated the resources\n\n";
                    for (long long int j = 0; j < s.resources; j++)
                    {
                        s.available[j] += s.allocated[i][j];
                    }
                    break;
                }
            }
        }
        if (!found)
        {
            cout << "Resources could not be allocated to any process.\n\n";
            return true;
        }
    }
    return false;
}

int main()
{
    cout << "BANKER'S DEADLOCK AVOIDANCE AND PREVENTION ALGORITHM C++ IMPLEMENTATION\n";
    cout << "Name: Aditya Anand\tRoll No.:20124009\t Branch: IT\n\n\n";

    long long int res = 0, pro = 0;
    cout << "Enter number of resources: ";
    cin >> res;
    if (res <= 0)
    {
        cout << "There are no resouces available\n";
        return 0;
    }
    cout << "Enter number of processes: ";
    cin >> pro;

    if (pro <= 0)
    {
        cout<<"No processes\n";
        return 0;
    }

    state s(res, pro);

    cout << "For " << pro << " processes enter: \n";
    for (long long int i = 0; i < pro; i++)
    {
        cout << "Resources allocated to process " << i + 1 << ": ";
        for (long long int j = 0; j < res; j++)
        {
            cin >> s.allocated[i][j];
        }
        cout << "Max resources required by process " << i + 1 << ": ";
        for (long long int j = 0; j < res; j++)
        {
            cin >> s.max_req[i][j];
            s.remaining_req[i][j] = s.max_req[i][j] - s.allocated[i][j];
        }
    }

    cout << "Enter the currently available resources: ";
    for (long long int i = 0; i < res; i++)
    {
        cin >> s.available[i];
    }

    cout << "\n\n---------------------------------------------------------------------------\n\n";
    bool deadlock = bankers(s);
    cout << "\n\n---------------------------------------------------------------------------\n\n";

    if (deadlock)
    {
        cout << "Deadlock Situation Detected!\n";
    }
    else
    {
        cout << "No Deadlock Detected!\n";
        cout << "Safe sequence of resource allocation: ";
        while (!safe_seq.empty())
        {
            cout << "P" << safe_seq.front() << " ";
            safe_seq.pop();
        }
        cout << "\n";
    }
    return 0;
}