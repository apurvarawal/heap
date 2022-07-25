#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq_maxheap;
    priority_queue <int, vector<int>, greater<int>> pq_minheap;

    int n;
    cin>>n;
    int data;
    for(int i=0; i<n; i++){
        cin>>data;
        pq_maxheap.push(data); //TIME COMPLEXITY: O(logN)
        pq_minheap.push(data);
    }

    for(int i=0; i<n; i++){
        cout<<pq_maxheap.top()<<" "; //TIME COMPLEXITY: O(1)
        pq_maxheap.pop(); //TIME COMPLEXITY: O(logN)
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<pq_minheap.top()<<" "; //TIME COMPLEXITY: O(1)
        pq_minheap.pop(); //TIME COMPLEXITY: O(logN)
    }

    return 0;
}