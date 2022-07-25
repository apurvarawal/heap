#include<bits/stdc++.h>
using namespace std;

void medianArr(int* arr, int n){
  priority_queue<int, vector<int>, greater<int>> minHeap;
  priority_queue<int, vector<int>> maxHeap;

  vector<int> median;
  int i=0;
  
  maxHeap.push(arr[i]);
  median.push_back(maxHeap.top());
  i++;

  while(i<n){
    if(arr[i]<maxHeap.top()){
      maxHeap.push(arr[i]);
      if(maxHeap.size()-minHeap.size()>1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
      }
    }
    else if(arr[i]>maxHeap.top()){
      minHeap.push(arr[i]);
    }
    if(minHeap.size()-maxHeap.size()>1){
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }

    if(maxHeap.size()==minHeap.size()){
        median.push_back((minHeap.top() + maxHeap.top())/2);
    }
    else if(maxHeap.size()-minHeap.size()==1){
      median.push_back(maxHeap.top());
    }
    else if(minHeap.size()-maxHeap.size()==1){
      median.push_back(minHeap.top());
    }
    i++;
  }
  for(int i=0; i<median.size(); i++){
    cout<<median[i]<<" ";
  }
}

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  medianArr(arr,n);
  return 0;
}
