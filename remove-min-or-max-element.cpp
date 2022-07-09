#include<bits/stdc++.h>
using namespace std;

// first we will swap the first and last element, then we will pop the last element which is the min element
// then we will put the 1st element to it's correct position, by heapify function.

class heap{
    vector <int> v;
    bool minheap;

    bool compare(int childElement, int parentElement){
        if(minheap){
            return parentElement>childElement;
        }else{
            return parentElement<childElement;
        }
    }

    void heapify(int parentIdx){
        int left = 2*parentIdx;
        int right = (2*parentIdx)+1;

        int min_Element_Idx = v[parentIdx]; //since we are starting comparison from 1st index, therefore, we take it as the first index.
        int last_idx = v.size()-1; //after popping the last element, the size is now reduced by 1.

        if(left<=last_idx && compare(v[left],v[parentIdx])){ // we will compare the root with the left node, if the node is smaller than 
            min_Element_Idx = left;                          // then we will set the min element index as the left.
        }
        if(right<=last_idx && compare(v[right],v[min_Element_Idx])){ //we will compare the now updated min element with the right side of the root
            min_Element_Idx = right;                                 //if right is smaller than the min element, then we will change the min element index to right.
        }
        if(min_Element_Idx!=parentIdx){ // if the min index is not equal to its initial value, that was parent index, then we will swap min element index with
            swap(v[min_Element_Idx],v[parentIdx]); // the parent index.
            heapify(min_Element_Idx); // then we will again run the same heapify function for the min element index, through recursion, till the root reaches the correct position.
        }
    }

    public:
    heap(int default_size=10, bool type = true){
        v.reserve(default_size);
        v.push_back(-1);
        minheap = type;
    }

    void push(int data){
        v.push_back(data);
        int child = v.size()-1;
        int parent = child/2;

        while(child>1 && compare(v[child],v[parent])){
            swap(v[child],v[parent]);
            child = parent;
            parent = child/2;
        }
    }
    void pop(){
        int n = v.size()-1;
        swap(v[1],v[n]); //swapping 1st and last element, so that we dont have to change the indices of all elemnts to bring them to the correct position.
        v.pop_back(); //popping the last element, which is the min element in case of min heap.
        heapify(1); // bringing the first element to the right position.
    }

    void print(){
        for(int i=1; i<=v.size()-1; i++){
            cout<<v[i]<<" ";
        }
    }
};
int main(){
    heap h;
    int data;
    for(int i=1; i<=10; i++){
        cin>>data;
        h.push(data);
    }
    h.pop();
    h.print();
    return 0;
}