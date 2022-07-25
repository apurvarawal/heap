#include<bits/stdc++.h>
#include<queue>

using namespace std;

class person{
    public:
    string name;
    int age;

    person(){
    }

    person(string n, int a){
        name = n;
        age = a;
    }
};

class compareAge{
    public:
    bool operator()(person A, person B){
        return A.age<B.age;
    }
};

int main(){
    int n;
    cin>>n;
    
    priority_queue <person, vector<person>, compareAge> pq;

    for(int i=0; i<n; i++){
        string name;
        int age;
        cin>>name>>age;
        person p(name,age);
        pq.push(p);
    }

    int k=3;
    for(int i=0; i<k; i++){
        person p1 = pq.top();
        cout<<p1.name<<" "<<p1.age<<", ";
        pq.pop();
    }
    return 0;
}