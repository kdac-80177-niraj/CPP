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
            if(size != 0){
                arr = new int[size];
                this->size = s.size;
            }else{
                arr = new int[SIZE];
                this->size = SIZE;
            }
            this->top = s.top;
            this->arr = s.arr;
            this->a = s.a;
        }

        void operator=(Stack s){
            this->arr = s.arr;
            this->top = s.top;
            this->size = s.size;
            this->a = s.a;
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

    Stack stack1(size);
    Stack stack2(size);
    stack2 = stack1;
    Emenu choice;
    while((choice=menu())!=EXIT){
        switch(choice){
            case EXIT:
                cout<<"exiting........."<<endl;
                break;
            case PUSH:
                stack1.push();
                break;
            case POP:
                stack1.pop();
                break;
            case PEEK:
                stack1.peek();
                break;
            case ISEMPTY:
                stack1.isEmpty();
                break;
            case ISFULL:
                stack1.isFull();
                break;
            case PRINT:
                stack1.print();
                break;
            case CLEAR:
                stack1.clear();
                break;
            default:
                cout<<"Wrong choice";
                break;

        }
    }
    stack2.pop();
    stack2.print();
    cout<<"thank you for choosing"<<endl;
    return 0;
}