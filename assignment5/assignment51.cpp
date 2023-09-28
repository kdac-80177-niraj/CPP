#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

class student{
    private:
        string name;
        string gender;
        int rollNumber;
        int m1;
        int m2;
        int m3;
    public:
        student(){
            this->name = "";
            this->gender = "";
            this->rollNumber = 0;
            this->m1 =1;
            this->m2 =1;
            this->m3 =1;
        }
        student(string name,string gender,int rollNumber,int m1,int m2,int m3){
            this->name = name;
            this->gender = gender;
            this->rollNumber = rollNumber;
            this->m1 =m1;
            this->m2 =m2;
            this->m3 =m3;
        }
        void acceptStudent(){
            cout<<"Enter student name: ";
            cin>>this->name;
            cout<<"Enter student gender: ";
            cin>>this->gender;
            cout<<"Enter student roll number: ";
            cin>>this->rollNumber;
            cout<<"Enter students marks in m1: ";
            cin>>this->m1;
            cout<<"Enter students marks in m2: ";
            cin>>this->m2;
            cout<<"Enter students marks in m3: ";
            cin>>this->m3;
        }
        void displayStudent(){
            float percentage;
            int total = 300;
            percentage = (m1+m2+m3)*100/total;
            cout<<"**********************************"<<endl;
            cout<<"Students Information"<<endl;
            cout<<"Student Name: "<<this->name<<endl;
            cout<<"Student Gender: "<<this->gender<<endl;
            cout<<"Student Roll Number: "<<this->rollNumber<<endl;
            cout<<"M1 marks: "<<this->m1<<endl;
            cout<<"M2 marks: "<<this->m2<<endl;
            cout<<"M3 marks: "<<this->m3<<endl;
            cout<<"Student Percentages: "<<percentage<<endl;
            cout<<"**********************************"<<endl;

        }
        int getRollNumber(){
            return rollNumber;
        }
};

void sortRecords(student arr[],int size){
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].getRollNumber() > arr[j + 1].getRollNumber()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i].getRollNumber()<<endl;
    }
}

int searchRecords(student arr[],int size,int rollNumber){
    for(int i = 0 ; i < size ; i++){
        if(rollNumber == arr[i].getRollNumber()){
            return i;
            break;
        }
    }
    return -1;
}

enum Emenu{
    EXIT,
    ADD,
    PRINT,
    SORT,
    SEARCH
};

Emenu menu(){
    int choice;
    cout<<"***************************"<<endl;
    cout<<"0) EXIT."<<endl;
    cout<<"1) ADD STUDENT."<<endl;
    cout<<"2) PRINT STUDENT."<<endl;
    cout<<"3) SORT BY ROLL NUMBERS."<<endl;
    cout<<"4) SEARCH STUDENT BY ROLL NUMBER."<<endl;
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;
    return Emenu(choice);
}



int main(){
    int size;
    int rollcall;
    cout<<"Number of students you want to add: ";
    cin>>size;
    student arr[size];
   Emenu choice;
   while((choice = menu())!= EXIT){
        switch(choice){
            case EXIT:
                cout<<"Exiting......"<<endl;
                break;
            case ADD:
                for(int i = 0 ; i < size ; i++){
                    arr[i].acceptStudent();
                }
                break;
            case PRINT:
                for(int i = 0 ; i < size ; i++){
                    arr[i].displayStudent();
                }
                break;
            case SORT:
                cout<<"sorted rolls as: "<<endl;
                sortRecords(arr,size);
                break;
            case SEARCH:
                cout<<"Enter roll you want to search: ";
                cin>>rollcall;
                int index = searchRecords(arr,size,rollcall);
                if(index != -1){
                    cout<<"Student found at index: "<<index<<endl;
                    arr[index].displayStudent();
                }
                else{
                    cout<<"Student not found......."<<endl;
                }
                break;  
        }
   }

    return 0;
}