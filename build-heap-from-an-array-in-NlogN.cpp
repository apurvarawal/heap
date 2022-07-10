#include<bits/stdc++.h>
using namespace std;

// Time complexity : O(NlogN)
// since we are iterating over each element and putting it at its correct position from the bottom of the tree, so in
// the worst case element has to travel the height of the tree, which takes logN time. So for N elements, time complexit
// will be O(NlogN).

void buildheap(vector <int> &v){
    for(int i=1; i<v.size(); i++){
        int child = i;
        int parent = child/2;
        if(i>1 && v[parent]<v[child]){
            swap(v[parent],v[child]);
            child = parent;
            parent = child/2;
        }
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
    print(v);
    buildheap(v);
    print(v);
    return 0;
}