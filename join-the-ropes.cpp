#include<bits/stdc++.h>
using namespace std;

long long minCost(long long* arr, long long n){
    priority_queue<long long, vector<long long>,greater<long long>> pq;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
    }

    long long cost = 0;
    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a+b;
        pq.push(sum);
        cost += sum;
    }
    return cost;
}
int main(){
    long long n;
    cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<minCost(arr,n);
    return 0;
}