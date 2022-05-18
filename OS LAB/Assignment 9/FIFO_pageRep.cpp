#include<bits/stdc++.h>
using namespace :: std;

int search(vector<int> arr, int key){
    for(int i=0; i<arr.size(); i++){
        if(arr[i]==key){
            return i;
        }
    }

    return -1;
}

void FIFO(vector<int> ref, int frames){
    vector<int> fr(frames, -1);
    int k = 0;
    int hit = 0, miss = 0;

    for(int i=0; i<ref.size(); i++){
        int id = search(fr, ref[i]);
        if(id!=-1){
            hit++;
        }
        else{
            fr[k]=ref[i];
            k=(k+1)%frames;
            miss++;
        }
    }

    cout<<"Hit Percentage: "<<(100.0*hit)/(1.0*(hit+miss))<<"%\n";
    cout<<"Miss Percentage: "<<(100.0*miss)/(1.0*(hit+miss))<<"%\n";
}

int main(){
    cout << "FIRST IN FIRST OUT PAGE REPLACEMENT ALGORITHM C++ IMPLEMENTATION\n";
    cout << "Name: Aditya Anand\tRoll No.:20124009\t Branch: IT\n\n\n";

    int frames = 0;
    cout<<"Enter the number of frames: ";
    cin>>frames;

    if(frames<1){
        cout<<"No frames available!";
        return 0;
    }

    cout<<"Enter the size of the reference string: ";
    int n = 0;
    cin>>n;

    cout<<"Enter the order in which pages are accessed by the CPU\n";
    vector<int> ref(n, 0);
    for(int i=0; i<n; i++){
        cin>>ref[i];
    }

    FIFO(ref, frames);

    return 0;

}