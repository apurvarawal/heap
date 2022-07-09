#include<bits/stdc++.h>
using namespace std;

// Since the condition for minheap is parent<child, so for swapping to occur, parent>child, that's why we returned true
// when the parent>child. Similar id the maxheap (else) case.

class heap{
    vector <int> v;
    bool minheap; //tell us whether the heap is min or max

    bool compare(int childElement, int parentElement){
        if(minheap){
            return childElement<parentElement;
        }else{
            return childElement>parentElement;
        }
    }
    public:
    heap(int default_size = 10, bool type = true){
        v.reserve(default_size); //make the vector of size 10, and will increase the size, only when all these 10 spaces are filled.
        v.push_back(-1); //pushing -1 on the 0th index.
        minheap = type; //initially heap will be minheap.        
    }

    void push(int data){
        v.push_back(data);
        int child = v.size()-1;
        int parent = child/2;
        
        while(child>1 && compare(v[child],v[parent])){
            swap(v[child],v[parent]);
            child=parent;
            parent=parent/2;
        }
    }
    void print(int data){
        for(int i=1; i<=10; i++){
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
    h.print(data);
    return 0;
}