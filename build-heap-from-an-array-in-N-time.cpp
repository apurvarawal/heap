#include<bits/stdc++.h>
using namespace std;

bool maxheap = false;

bool compare(int parentElement, int ChildElement){
    if(maxheap){
        return parentElement < ChildElement;
    }else{
        return parentElement > ChildElement;
    }
}

void heapify(vector<int> &v, int i){
    int parentIdx = i;
    int left = 2*parentIdx;
    int right = (2*parentIdx)+1;

    int last = v.size()-1;
    int max_idx = parentIdx;
    if(left<=last && compare(v[left],v[parentIdx])){
        max_idx = left;
    }
    if(right<=last && compare(v[right],v[max_idx])){
        max_idx = right;
    }

    if(max_idx!=parentIdx){
        swap(v[max_idx],v[parentIdx]);
        heapify(v,max_idx);
    }
}

void buildOptimisedHeap(vector <int> &v){
    for(int i=v.size()/2; i>=1; i--){
        heapify(v,i);
    }
}

void print(vector <int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector <int> v = {-1,10,20,5,6,1,8,9,4};
    buildOptimisedHeap(v);
    print(v);
    return 0;
}