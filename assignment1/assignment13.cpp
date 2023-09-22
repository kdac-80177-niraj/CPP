#include<iostream>
using namespace std;

class Student{
    private:
        int roll_no;
        string name;
        int marks;

    public:
        void initStudent(){
            roll_no=100;
            name = "sunbeam";
            marks=30;
        }

        void printStudentOnConsole(){
            cout<<"Student Roll Number is: "<<roll_no<<endl;
            cout<<"Student Name is: "<<name<<endl;
            cout<<"Students Marks Are: "<<marks<<endl;
        }

        void acceptStudentFromConsole(){
            cout<<"Enter student name: \n"<<endl;
            cin>>name;

            cout<<"Enter student roll number: \n"<<endl;
            cin>>roll_no;

            cout<<"Enter student marks: \n"<<endl;
            cin>>marks;
        }
};

int main(){
    Student stud;
    stud.initStudent();

    int choice;

    do{
        cout<<"\nMenu\n";
        cout<<"1. Init student\n";
        cout<<"2. Accept student\n";
        cout<<"3. Display Student\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: stud.initStudent();
            stud.printStudentOnConsole();
            break;
            case 2: stud.acceptStudentFromConsole();
            break;
            case 3: stud.printStudentOnConsole();
            break;
            case 4: cout<<"exiting....";
            break;
            default: cout<<"Wrong choice!!!! Enter proper choice.\n";
        }
        /*cout<<"Enter choice again....\n";
        cin>>choice;
        if(choice == 4){
            cout<< "exiting......";
        }*/

    }while(choice != 4);
    return 0;
}