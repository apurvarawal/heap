#include<bits/stdc++.h>
using namespace std;

class fun{
    public:
    void operator()(string s){
        cout<<"hey!! i m in functor with "<<s;
    }
};

int main(){
    fun f; //constructor
    f("C++."); //overloaded operator() = function call where f is an object.
}