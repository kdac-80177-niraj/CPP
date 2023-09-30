#include<iostream>
using namespace std;
class Employee{
    private:
    int empid;
    double sal;
    string des;
    public:
    Employee()
    {
        this->empid=0;
        this->sal=0;
        this->des = "";
    }
    Employee(int id,double sal,string des)
    {
        this->empid=id;
        this->sal=sal;
        this->des = des;
    }
    void setEmployee(int id,double sal,string des)
    {
        this->empid=id;
        this->sal=sal;
        this->des=des;
    }
    int getId()
    {
        return this->empid;
    }
    void setId(int empid)
    {
        this->empid=empid;
    }
    void setSal(double sal)
    {
        this->sal=sal;
    }
    void displayDes(){
        cout<<this->des;
    }
    void setDesignation(string des){
        this->des = des;
    }
    int getSal()
    {
        return this->sal;
    }
    string designation(){
        return this->des;
    }
    virtual void accept()
    {
        cout<<"Enter Employee Id: "<<endl;
        cin>>this->empid;
        cout<<"Enter Salary: "<<endl;
        cin>>this->sal;
        cout<<"Enter Designation: "<<endl;
        cin>>this->des;
    }
     void display()
    {
        cout<<"Empid= "<<this->empid<<endl;
        cout<<"Salary= "<<this->sal<<endl;
        cout<<"Designation= "<<this->des<<endl;
    }

};
class Manager: virtual public Employee {
    private:
    double bonus;
    string des;
    public:
    Manager()
    {
        this->bonus=0;
    }
    Manager(int empid,double sal,string des,double bonus)
    {
        Employee(empid,sal,des);
        this->bonus=bonus;
    }
    void setManager(int empid,double sal,string des, double bonus)
    {
        Employee::setEmployee(empid,sal,des);
        this->bonus=bonus;
    }
    void setBonus(double bonus)
    {
        this->bonus=bonus;
    }
    double getBonus()
    {
        return this->bonus;
    }
    string designation(){
        return this->des;
    }
    
    void accept()
    {
        Employee::accept();
        cout<<"Enter Bonus"<<endl;
        cin>>this->bonus;
    }
    void display()
    {
        Employee::display();
        cout<<"Bonus= "<<this->bonus<<endl;
    }
    protected:
    void accept_Manager()
    {
        Employee::accept();
        cout<<"Enter Bonus"<<endl;
        cin>>this->bonus;
    }

    void display_Manager()
    {
        //Employee::display();
        cout<<"Bonus= "<<this->bonus<<endl;
    }
   
};
class Salesman: virtual public Employee{
    private:
    double comm;
    string des;
    public:
    Salesman(){
        this->comm=0;
    }
    Salesman(int empid,double sal,string des,double comm)
    {
        Employee(empid,sal,des);
        this->comm=comm;
    }
    double getComission()
    {
        return this->comm;
    }
    void setCommission(double comm)
    {
        this->comm=comm;
    }
    string designation(){
        return this->des;
    }
    
    void accept()
    {
        Employee::accept();
        cout<<"Enter Commission"<<endl;
        cin>>this->comm;
    }
    void display()
    {
        Employee::display();
        cout<<"Commission= "<<this->comm<<endl;
    }
    protected:
    void accept_Salesman()
    {
        
        cout<<"Enter Commission"<<endl;
        cin>>this->comm;
    }
    void display_Salesman()
    {
        cout<<"Commission= "<<this->comm<<endl;
    }

};
class Sales_manager:public Salesman,public Manager{
    private:
    string des;
    public:
    Sales_manager()
    {

    }
    Sales_manager(int empid,double sal,string des,double bonus,double comm)
    {
        Manager::setManager(empid,sal,des,bonus);
        Salesman::setCommission(comm);
    }
    string designation(){
        return this->des;
    }
    void accept()
    {
        //Employee::accept();
        Manager::accept_Manager();
        Salesman::accept_Salesman();
    }
    void display()
    {
        Employee::display();
        Manager::display_Manager();
        Salesman::display_Salesman();
    }
};
int menu(){
    int choice;
    cout<<"***********************"<<endl;
    cout<<"0. EXIT."<<endl;
    cout<<"1. Accept Manager."<<endl;
    cout<<"2. Accept Salesman."<<endl;
    cout<<"3. Accept Sales-Manager."<<endl;
    cout<<"4. Employee Count(W.R.T to Designation)."<<endl;
    cout<<"5. Designation Was Employee."<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<"***********************"<<endl;
    return choice;
}
int main()
{
    int choice;
    Employee *arr[10];
    int index = 0;
    int ecount = 0;
    int mcount = 0;
    int scount = 0;
    int s_mcount = 0;
    while((choice = menu())!=0){
        switch(choice){
            case 1:
                if(index<10){
                    arr[index]= new Manager();
                    arr[index]->accept();
                    ecount++;
                    mcount++;
                    index++;
                }else{
                    cout<<"List full, you cannot add Manager..."<<endl;
                }
                break;
            case 2:
                if(index<10){
                    arr[index] = new Salesman();
                    arr[index]->accept();
                    ecount++;
                    scount++;
                    index++;
                }else{
                    cout<<"List full, you cannot add Salesman..."<<endl;
                }
                break;
            case 3:
                if(index<10){
                    arr[index] = new Sales_manager();
                    arr[index]->accept();
                    ecount++;
                    s_mcount++;
                    index++;
                }else{
                    cout<<"List full, you cannot add Sales-Manager..."<<endl;
                }
                break;
            case 4:
                cout<<"***********************"<<endl;
                cout<<"Employee count: "<<ecount<<endl;
                cout<<"Manager count: "<<mcount<<endl;
                cout<<"Salesman count: "<<scount<<endl;
                cout<<"Sales-Manager count: "<<s_mcount<<endl;
                cout<<"***********************"<<endl;
                break;
            case 5:
                /*for(int i = 0 ; i < index ; i++){
                   arr[i]->display();
                }*/
                for(int i = 0 ; i < index ; i++){
                if(arr[i]->designation() == "manager"){
                    cout<<"************************"<<endl;
                    cout<<"Manager's"<<endl;
                    arr[i]->display();
                }
                if(arr[i]->designation() == "salesman"){
                    cout<<"************************"<<endl;
                    cout<<"Salesman's"<<endl;
                    arr[i]->display();
                }
                if(arr[i]->designation() == "salesmanager"){
                    cout<<"************************"<<endl;
                    cout<<"Salesman-Manager's"<<endl;
                    arr[i]->display();
                }
                }
                break;
            default:
                cout<<"Wrong choice....."<<endl;
        }
    }
    for(int i = 0 ; i < index ; i++){
        delete arr[i];
    }
    return 0;
}