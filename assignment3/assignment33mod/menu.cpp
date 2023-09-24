#include "./menu.h"
#include<iostream>
using namespace std;


Emenu menu(){
    int choice;
    cout<<"****************************"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. GET RADIUS: "<<endl;
    cout<<"2. UPDATE RADIUS: "<<endl;
    cout<<"3. GET HEIGHT: "<<endl;
    cout<<"4. UPDATE HEIGHT: "<<endl;
    cout<<"5. GET VOLUME: "<<endl;
    cout<<"6. PRINT VOLUME: "<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    cout<<"****************************"<<endl;
    return Emenu(choice);
}