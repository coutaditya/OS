// C++ implementation of solution of Sleeping Barber Problem using Semaphore (Process Synchronisation)
#include<bits/stdc++.h>
using namespace :: std;

int cut_time=0;

struct binarySemaphore{
    bool s;
};

struct countingSemaphore{
    int s;
};

void customer(binarySemaphore &barber, binarySemaphore &cut, int Customers){
    int id=1;
    while(id<=Customers){
        // Wake the barber up if he is sleeping
        if(barber.s==0){
            barber.s=1;
        }
        
        // Cut the hair
        cut.s=1;
        cout<<"Customer "<<id<<" is getting a haircut\n\n";
        cut.s=0;

        id++;
    }

    // The barber goes to sleep after tending to all the customers
    barber.s=0;
}

int main(){
    cout<<"SOLUTION TO SLEEPING BARBER PROBLEM USING SEMAPHORE C++ IMPLEMENTATION\n";
    cout<<"Name: Aditya Anand\tRoll No.:20124009\t Branch: IT\n\n\n";

    binarySemaphore barber;    // denotes if the barber is sleeping or awake    
    binarySemaphore cut;       // semaphore to synchronise hair cutting
    countingSemaphore freeChairs;

    cout<<"Enter the number of free chairs: ";
    cin>>freeChairs.s;

    barber.s=0; // initially the barber is sleeping
    cut.s=0;

    // Suppose the customers visit the shop in groups. The group visits the barber only after all the customers of first group have left the shop. 
    while(1){
        int freeSpace=freeChairs.s;
        int customers=0;
        cout<<"Enter the number of customers entering the shop (enter 0 to exit): ";
        cin>>customers;

        if(customers==0){
            break;
        }

        // The first customer can always go to the sleeping barber
        int id=2;
        while(id<=customers){
            // Chair occupied by customer
            freeChairs.s--;
            id++;
            if(freeChairs.s==0){
                break;
            }
            
        }

        while(id<=customers){
            cout<<"Customer "<<id<<" returned back without getting a haircut\n";
            id++;
        }

        customer(barber, cut, (freeSpace-freeChairs.s+1));
        freeChairs.s=freeSpace;
    }
    
    return 0;
}