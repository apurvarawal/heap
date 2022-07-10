#include<bits/stdc++.h>
using namespace std;

void print(vector <int> v){
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

bool maxheap = true;

bool compare(int parent, int child){
    if(maxheap){
        return parent>child;
    }else{
        return parent<child;
    }
}

void heapify(vector<int> &v, int i, int size){
    int parent = i;
    int left = 2*i;
    int right = left+1;

    int maxIdx = parent;
    int last = size-1;
    if(left<=last && compare(v[parent], v[left])){
        maxIdx = left;
    }
    if(right<=last && compare(v[maxIdx],v[right])){
        maxIdx = right;
    }
    if(maxIdx!=parent){
        swap(v[parent],v[maxIdx]);
        heapify(v,maxIdx,size);
    }
}

void buildheap(vector<int> &v){
    for(int i=v.size()-1; i>=1; i--){
        heapify(v,i,v.size());
    }
}

void heapsort(vector <int> &arr){
    buildheap(arr);
    int n=arr.size();
    while(n>1){ 
        swap(arr[1],arr[n-1]);
        n--;
        heapify(arr,1,n);
    }
}


int main(){
    vector <int> v;
    v.push_back(-1);
    int data;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        v.push_back(data);
    }
    heapsort(v);
    print(v);
    return 0;
}