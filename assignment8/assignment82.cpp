#include<iostream>
using namespace std;
#define SIZE 3

class Stack{
    private:
        int size;
        int top;
        int *arr;
        int a;
    public:
        Stack(){
            this->top = -1;
            if(size != 0){
                arr = new int[size];
                this->size = size;
            }else{
                arr = new int[SIZE];
                this->size = SIZE;
            }
        }
        Stack(int sz){
            this->top = -1;
            if(size != 0){
                arr = new int[size];
                this->size = size;
            }else{
                arr = new int[SIZE];
                this->size = SIZE;
            }

        }
        Stack(Stack &s){
            this->top = s.top;
            this->size = s.size;
            this->arr = new int[size];
            for(int i = 0 ; i <= top ; i++){
                this->arr[i] = s.arr[i];
            }

        }

        void operator=(Stack s){
            this->top = s.top;
            this->size = s.size;
            this->arr = new int[size];
            for(int i = 0 ; i <= top ; i++){
                this->arr[i] = s.arr[i];
            }
        }

        void push(){
            if(this->top == size-1){
                cout<<"Stack is full, Pushing not allowed"<<endl;
            }else{
                this->top++;
                cout<<"Enter number: ";
                cin>>a;
                this->arr[top] = a;
            }
        }
        void pop(){
            if(this->top == -1){
                cout<<"Stack is empty"<<endl;
            }else{
                cout<<"Popped number is: "<<this->arr[top]<<endl;
                this->arr[top] = 0;
                this->top--;
            }
        }
        void peek(){
            if(this->top == -1){
                cout<<"Empty stack...."<<endl;
            }else{
                cout<<"Peeked element is: "<<this->arr[top]<<endl;
            }
        }

        void isEmpty(){
            if(this->top == -1){
                cout<<"Stack is empty"<<endl;
            }else{
                cout<<"Stack is not empty"<<endl;
            }
        }
        void isFull(){
            if(this->top == size-1){
                cout<<"Stack is full"<<endl;
            }else{
                cout<<"Stack is not full"<<endl;
            }
        }
        void print(){
            if(this->top == -1 or this->top == size){
                cout<<"Not possible"<<endl;
            }
            else{
            for(int i = 0 ; i < size ; i++){
                cout<<this->arr[i]<<endl;
            }
            }
        }
        void clear(){
            delete[] arr;
        }
};

int main(){
    Stack s1;
    s1.push();
    s1.push();
    s1.push();
    s1.print();
    Stack s2;
    s2 = s1;
    s2.print();
    s1.pop();
    s2.print();
    s1.print();
}