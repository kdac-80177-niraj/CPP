#include<iostream>
using namespace std;

int factorial(int n){
    int result=1;
    if(n < 0)
        throw -2;
    if(n == 0)
        return 1;
    else{
        for(int i = 1 ; i <= n ; i++){
            result *= i;
        }
    }
    return result;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    try{
        int f = factorial(n);
        cout<<"factorial is: "<< f <<endl;
    }
    catch(int error){
        cout<<"negative numbers don't have factorials"<<endl;
    }
    return 0;
}