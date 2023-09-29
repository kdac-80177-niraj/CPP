#include<iostream>
using namespace std;

//class date
class date
{
private:
    int day;
    int month;
    int year;
public:
    date() //parameterless ctor
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    date(int day, int month, int year) //parameterized ctor
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void acceptdate() //fascilitator
    {
        cout << "Enter the day = ";
        cin >> this->day;
        cout << "Enter the month = ";
        cin >> this->month;
        cout << "Enter the year = ";
        cin >> this->year;
    }
    void displaydate()
    {
        cout << this->day << "/" << this->month << "/" << this->year << endl;
    }
    int getDay(){ //getter
        return this->day;
    }
    void setDay(int day){ //setter
        this->day = day;
    }
    int getmonth(){
        return this->month;
    }
    int getYear(){
        return this->year;
    }
    void setMonth(int month){
        this->month = month;
    }
    void setYear(int year){
        this->year = year;
    }
    bool isLeapYear() {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    void leap(){
        if(isLeapYear()){
            cout<<"Leap Year"<<endl;
        }else{
            cout<<"Not A Leap Year"<<endl;
        }
    }

};
//class employee
class employee{
    private:
        int id;
        float sal;
        string dept;
        date joining;
        date empBirth;
    public:
        employee(){
            this->id = 0;
            this->sal = 0;
            this->dept = "";
        }
        employee(int id,float sal,string dept,int day,int month,int year):joining(day,month,year),empBirth(day,month,year){
            this->id = id;
            this->sal = sal;
            this->dept = dept;
        }
        void acceptEmployee(){
            cout<<"Enter employee id: ";
            cin>>id;
            cout<<"Enter employee sal: ";
            cin>>sal;
            cout<<"Enter employee dept: ";
            cin>>dept;
            joining.acceptdate();
            cout<<"Enter employee Birth date: ";
            empBirth.acceptdate();
        }
        void displayEmployee(){
            cout << "Empid = " << this->id << endl;
            cout << "sal = " << this->sal << endl;
            cout << "dept = " << this->dept << endl;
            cout << "date of joining = ";
            joining.displaydate();
        }
        int getid(){
            return id;
        }
        void setid(int id){
            this->id = id;
        }
        float getsal(){
            return sal;

        }
        void setsal(float sal){
            this->sal = sal;
        }
        string getdept(){
            return dept;
        }
        void setdept(string dept){
            this->dept = dept;
        }
        date getdoj(){
            cout<<"Joining Date is: "<<joining.getDay()<<"/"<<joining.getmonth()<<"/"<<joining.getYear()<<endl;
            return joining;
        }
        void setdoj(int day,int month,int year){
            joining.setDay(day);
            joining.setMonth(month);
            joining.setYear(year);
        }

};
//class person
class person{
    private:
        string name;
        string addr;
        date Birth;
    public:
        person(){
            this->name="";
            this->addr="";
        }
        person(string name,string addr,int day,int month,int year):Birth(day,month,year){
            this->name = name;
            this->addr = addr;
        }
        void acceptPerson(){
            cout<<"Enter person name: ";
            cin>>name;
            cout<<"Enter address: ";
            cin>>addr;
            cout<<"Enter Birth Date: ";
            Birth.acceptdate();
        }
        void displayPerson(){
            cout<<"Person name is: "<<this->name<<endl;
            cout<<"person address is: "<<this->addr<<endl;
            cout<<"Birth date is: ";
            Birth.displaydate();
        }
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        string getAddress(){
            return addr;
        }
        void setAddress(string addr){
            Birth.acceptdate();
        }
        date getBirth(){
            
            cout<<"Birth Date is: "<<Birth.getDay()<<"/"<<Birth.getmonth()<<"/"<<Birth.getYear()<<endl;
            return Birth;
        }
        void setBirth(int day,int month,int year){
            Birth.setDay(day);
            Birth.setMonth(month);
            Birth.setYear(year);
        }
};

int main(){
    return 0;
}