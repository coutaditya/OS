#include<bits/stdc++.h>
using namespace :: std;

struct frame{
    int frNo, lastOcc;
};

// returns the index at which the key is found and the index of the least recently used page
pair<int, int> Search(vector<frame> &arr, int key, vector<int> ref, int cur){
    int id = -1, lru = INT_MAX;

    for(int i=0; i<arr.size(); i++){
        if(arr[i].frNo==key){
            id = i;
        }
        for(int j=cur-1; j>=0; j--){
            if(ref[j]==arr[i].frNo){
                arr[i].lastOcc = j;
                lru = min(lru, arr[i].lastOcc);
                break;
            }
        }
    }

    int pRep = -1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i].lastOcc == lru){
            pRep = i;
            break;
        }
    }

    return make_pair(id, pRep);
}

void LRU(vector<int> ref, int frames){
    vector<frame> fr(frames);
    for(int i=0; i<frames; i++){
        fr[i].frNo = -1;
        fr[i].lastOcc = -1;
    }
    int hit = 0, miss = 0;
    int k=0, it=0;

    while(k<frames && it<ref.size()){
        bool found = false;
        for(int j=k; j>=0; j--){
            if(fr[j].frNo == ref[it]){
                found=true;
                hit++;
                break;
            }
        }

        if(!found){
            fr[k].frNo = ref[it];
            fr[k].lastOcc = it;
            miss++;
            k++;
        } 
        it++;
    }

    for(int i=it; i<ref.size(); i++){
        pair<int , int> p = Search(fr, ref[i], ref, i);
        if(p.first!=-1){
            hit++;
        }
        else{
            fr[p.second].frNo=ref[i];
            fr[p.second].lastOcc=i;
            miss++;
        }
    }

    cout<<"Hit Percentage: "<<(100.0*hit)/(1.0*(hit+miss))<<"%\n";
    cout<<"Miss Percentage: "<<(100.0*miss)/(1.0*(hit+miss))<<"%\n";
}

int main(){
    cout << "LEAST RECENTLY USED REPLACEMENT ALGORITHM C++ IMPLEMENTATION\n";
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
    vector<int> ref(n);
    for(int i=0; i<n; i++){
        cin>>ref[i];
    }

    LRU(ref, frames);

    return 0;

}