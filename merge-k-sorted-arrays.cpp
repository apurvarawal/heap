#include<bits/stdc++.h>
using namespace std;

void mergeKsortedArrays(vector<vector<int>> arr,int k){
    priority_queue<int, vector<int> , greater<int>> minheap;

    for(int i=0; i<k ;i++){
        for(int j=0; j<k; j++){
            minheap.push(arr[i][j]);
        }
    }

    vector<int> v;

    while(!minheap.empty()){
        v.push_back(minheap.top());
        minheap.pop();
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;            
        vector<vector<int>> arr(k, vector<int> (k,0));
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                cin>>arr[i][j];
            }
        }
        mergeKsortedArrays(arr,k);
    }
    
    return 0;
}