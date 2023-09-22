#include<iostream>
using namespace std;


int roll_no = 12;
string name = "abhishek";
namespace NStudent{
    class Student{
        int roll_no = 10;
        string name = "Niraj";
        int marks = 30;
    };

    namespace Nstudent1{
        int roll_no = 1;
        string name = "raj";
        int marks = 3;
    }
}

int main(){
    int marks = 50;
    int roll_no = 40;
    string name = "rutik";

    cout<<"Local value of roll_no: "<<roll_no<<endl;
    cout<<"Global value of roll_no: "<<::roll_no<<endl;
    cout<<"student1 value of roll_no: "<<NStudent::Nstudent1::roll_no<<endl;
    return 0;
}