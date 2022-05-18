// Solution of the Producer Consumer Problem using semaphore

#include<bits/stdc++.h>
using namespace :: std;

// Inititally we have an empty buffer with a size 5
long long int bs;
int m=1;                    // Mutex
int full=0;                 // Counting Semaphore
int empty=0;                // Counting Semaphore
int IN=0;
int OUT=0;

void down(int &s){
    s--;
}

void up(int &s){
    s++;
}

void producer(){
    down(m);
    up(full);
    down(empty);

    IN++;
    cout<<"\nProducer produced the item "<<IN;
    up(m);
}

void consumer(){
    down(m);
    down(full);
    up(empty);

    OUT++;
    cout<<"\nConsumer consumed the item "<<OUT;
    up(m);
}

int main(){
    cout<<"SOLUTION OF PRODUCER CONSUMER PROBLEM USING SEMAPHORE AND MUTEX C++ IMPLEMENTATION\n";
    cout<<"Name: Aditya Anand\tRoll No.:20124009\t Branch: IT\n\n\n";

    cout<<"Input the buffer size:\n";
    cin>>bs;
    empty=bs;

    int n=0;
    while(1){
        cout<<"Select the preference: (1, 2, or 3) \n";
        cout<<"1) Producer\n2)Consumer\n3)Exit\n";

        cin>>n;

        if(n==1){
            if(m==1 && empty!=0){
                producer();
                cout<<endl;
            }
            else{
                cout<<"Buffer is full\n";
            }
        }
        else if(n==2){
            if(m==1 && full!=0){
                consumer();
                cout<<endl;
            }
            else{
                cout<<"Buffer is empty\n";
            }
        }
        else{
            break;
        }
    }
    return 0;
    
}