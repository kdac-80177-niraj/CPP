#include<iostream>
using namespace std;
class Employee{
    private:
    int empid;
    double sal;
    public:
    Employee()
    {
        this->empid=0;
        this->sal=0;
    }
    Employee(int id,double sal)
    {
        this->empid=id;
        this->sal=sal;
    }
    void setEmployee(int id,double sal)
    {
        this->empid=id;
        this->sal=sal;
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
    int getSal()
    {
        return this->sal;
    }
    void accept()
    {
        cout<<"Enter Employee Id"<<endl;
        cin>>this->empid;
        cout<<"Enter Salary"<<endl;
        cin>>this->sal;
    }
    void display()
    {
        cout<<"Empid= "<<this->empid<<endl;
        cout<<"Salary= "<<this->sal<<endl;
    }
};
class Manager: virtual public Employee {
    private:
    double bonus;
    public:
    Manager()
    {
        this->bonus=0;
    }
    Manager(int empid,double sal,double bonus)
    {
        Employee(empid,sal);
        this->bonus=bonus;
    }
    void setManager(int empid,double sal,double bonus)
    {
        Employee::setEmployee(empid,sal);
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
        Employee::display();
        cout<<"Bonus= "<<this->bonus<<endl;
    }
   
};
class Salesman: virtual public Employee{
    private:
    double comm;
    public:
    Salesman(){
        this->comm=0;
    }
    Salesman(int empid,double sal,double comm)
    {
        Employee(empid,sal);
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
    public:
    Sales_manager()
    {

    }
    Sales_manager(int empid,double sal,double bonus,double comm)
    {
        Manager::setManager(empid,sal,bonus);
        Salesman::setCommission(comm);
    }
    void accept()
    {
        //Employee::accept();
        Manager::accept_Manager();
        Salesman::accept_Salesman();
    }
    void display()
    {
        //Employee::display();
        Manager::display_Manager();
        Salesman::display_Salesman();
    }
};
int main()
{
    Sales_manager s;
     s.accept();
    s.display();
     //Sales_manager s(10,15000,500,200);
     //s.display();
    //  Salesman s;
    // s.accept();
    // s.display();
    return 0;
}