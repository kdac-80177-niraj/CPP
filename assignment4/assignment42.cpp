#include<iostream>
#include<stdlib.h>
using namespace std;
#define SIZE 5

class Stack{
    private:
        int a;
        int top;
        int size;
        int *arr; //array of pointers
    public:
        Stack(int sz){
            this->top = -1;
            if(size!=0){
                this->arr = new int[sz];
                this->size = sz;
            }else{
                this->arr = new int[SIZE];
                this->size = SIZE;
            }
        }
        void push(){
            if(this->top == size -1){
                cout<<"Stack is full"<<endl;
            }
            else{
                this->top++;
                cout<<"Enter a number: ";
                cin>>a;
                this->arr[top] = a;
            }
        }
        void pop(){
            if(this->top == -1){
                cout<<"stack is empty"<<endl;
            }
            else{
                cout<<"popped number is: "<<this->arr[top]<<endl;
                this->arr[top]=0;
                this->top--;
            }

        }
        void peek(){
            if(this->top == -1){
                cout<<"Stack is empty"<<endl;
            }else{
                cout<<"peeked value is: "<<this->arr[top]<<endl;
            }
        }
        void isEmpty(){
            if(this->top == -1){
                cout<<"Stack is empty"<<endl;
            }else{
                cout<<"stack is not empty"<<endl;
            }
        }
        void isFull(){
            if(this->top == size-1){
                cout<<"Stack is full"<<endl;
            }else{
                cout<<"stack is not full"<<endl;
            }
        }
        void print(){
            if(this->top == -1 or this->top == size){
                cout<<"not possible"<<endl;
            }else{
                for (int i = 0 ; i < size ; i++){
                    cout<<this->arr[i]<<endl;
                }
            }
        }

        void clear(){
            delete[] arr;
        }
};

enum Emenu{
    EXIT,
    PUSH,
    POP,
    PEEK,
    ISEMPTY,
    ISFULL,
    PRINT,
    CLEAR
};

Emenu menu(){
    int choice;
    cout<<"**********************************"<<endl;
    cout<<"0. EXIT."<<endl;
    cout<<"1. PUSH."<<endl;
    cout<<"2. POP."<<endl;
    cout<<"3. PEEK."<<endl;
    cout<<"4. ISEMPTY."<<endl;
    cout<<"5. ISFULL."<<endl;
    cout<<"6. PRINT."<<endl;
    cout<<"7. CLEAR."<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    cout<<"***********************************"<<endl;
    return Emenu(choice);
}

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    /*Stack s(6);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.pop();
    s.print();*/

    class Stack stack(size);
    Emenu choice;
    while((choice=menu())!=EXIT){
        switch(choice){
            case EXIT:
                cout<<"exiting........."<<endl;
                break;
            case PUSH:
                stack.push();
                break;
            case POP:
                stack.pop();
                break;
            case PEEK:
                stack.peek();
                break;
            case ISEMPTY:
                stack.isEmpty();
                break;
            case ISFULL:
                stack.isFull();
                break;
            case PRINT:
                stack.print();
                break;
            case CLEAR:
                stack.clear();
                break;
            default:
                cout<<"Wrong choice";
                break;

        }
    }
    cout<<"thank you for choosing"<<endl;
    return 0;
}