#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

template <class s>
class stack{
    private:
        s a;
        int top=-1;
        vector<s> v1;
    public:
        void push(const s &a){
            if(top == v1.size()){
                cout<<"Stack is full"<<endl;
            }else{
                this->top++;
                v1.push_back(a);
            }
        }
        void pop(){
            if(top == -1)
                throw "stack is empty";
            v1.pop_back();
            this->top--;
        }

        s topelement(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
            }else{
                return v1.at(top);
            }
        }
};

int main(){
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    cout<< s1.topelement()<<endl;

    stack<double> s2;




}