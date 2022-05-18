/*
DINING PHILOSOPHER PROBLEM

The Dining Philosopher Problem states that K philosophers seated around a circular table with
one chopstick between each pair of philosophers. There is one chopstick between each
philosopher. A philosopher may eat if he can pick up the two chopsticks adjacent to him. One
chopstick may be picked up by any one of its adjacent followers but not both.

*/
#include <bits/stdc++.h>
using namespace ::std;

void display(){
    cout << "\n20124009 Aditya Anand\n";
    cout << "IT G1\n\n";
}

queue<int> ready;

struct binarySemaphore
{
    bool s;

    bool down()
    {
        if (!s)
        {
            return false;
        }

        s = 0;

        return true;
    }

    bool up()
    {
        if (s)
        {
            return false;
        }

        s = 1;
        return true;
    }
};

struct countingSemaphore
{
    int s;

    bool down()
    {
        if (s == 0)
        {
            return false;
        }

        s--;

        return true;
    }

    bool up(int n)
    {
        if (s == n)
        {
            return false;
        }

        s++;
        return true;
    }
};

void philosopherEat(int phil, vector<binarySemaphore> &fork, queue<int> &temp2, int n)
{
    cout << "Philosopher " << phil << " is hungry\n";
    if (fork[(phil - 1) % n].down())
    {
        if (fork[(phil) % n].down())
        {
            cout << "Philosopher " << phil << " has started eating\n";
            temp2.push(phil);
        }
        else
        {
            fork[(phil - 1) % n].up();
            cout << "Forks are not available for Philosopher " << phil << " to use\n";
            ready.push(phil);
            return;
        }
    }
    else
    {
        cout << "Forks are not available for Philosopher " << phil << " to use\n";
        ready.push(phil);
    }
}

void philosopherFinish(vector<binarySemaphore> &fork, queue<int> &temp2, int n)
{
    while (!temp2.empty())
    {
        int phil = temp2.front();
        temp2.pop();

        cout << "Philosopher " << phil << " has finished eating\n";
        fork[(phil - 1) % n].up();
        fork[(phil) % n].up();
    }
}

void DiningPhilosopher(int n)
{
    vector<binarySemaphore> fork(n);

    // Initially all the forks are available
    for (int i = 0; i < n; i++)
    {
        fork[i].s = true;
    }

    while (true)
    {
        if (ready.empty())
        {
            break;
        }

        queue<int> temp1, temp2;

        while (!ready.empty())
        {
            temp1.push(ready.front());
            // temp2.push(ready.front());
            ready.pop();
        }

        while (!temp1.empty())
        {
            int phil = temp1.front();
            temp1.pop();

            philosopherEat(phil, fork, temp2, n);
        }

        while (!temp2.empty())
        {
            philosopherFinish(fork, temp2, n);
        }
    }
}

int main()
{
    display();
    cout << "SOLUTION TO DINING PHILOSOPHER PROBLEM USING SEMAPHORE C++ IMPLEMENTATION\n";
    cout << "Enter the number of philosophers:\n";
    int n;
    cin >> n;
    if (n <= 0)
    {
        printf("Zero philosophers!!!!!\n");
        return 0;
    }
    cout << "There are " << n << " philosophers(numbered 1-n) sitting on a round table and " << n << " forks.\n";
    cout << "Enter the order in which Philosphers get hungry: ";

    for (int i = 0; i < n; i++)
    {
        int n = 0;
        cin >> n;
        ready.push(n);
    }

    DiningPhilosopher(n);

    return 0;
}

