#include<iostream>
using namespace std;

class employee{
    private:
        int id;
        float sal;
    public:
        employee(){
            cout<<"Employee ctor(less)"<<endl;
            this->id = 0;
            this->sal = 0;
        }
        employee(int id,float sal){
            cout<<"Employee ctor"<<endl;
            this->id = id;
            this->sal = sal;
        }
        void accept(){
            cout<<"Enter employee id: ";
            cin>>id;
            cout<<"Enter employee salary: ";
            cin>>sal;
        }
        void display(){
            cout<<"Employee id is: "<<this->id<<endl;
            cout<<"Employee salary is: "<<this->sal<<endl;
        }
        int getId(){
            return this->id;
        }
        void setId(int id){
            this->id = id;
        }
        int getSal(){
            return this->sal;
        }
        void setSal(float sal){
            this->sal = sal;
        }

        
};

class manager:virtual public employee{
    private:
        float bonus;
    public:
    employee e;
        manager(){
            cout<<"manager ctor(less)"<<endl;
            this->bonus = 0;
        }
        manager(float bonus){
            cout<<"manager ctor"<<endl;
            this->bonus = bonus;
        }
        void accept(){
            employee::accept();
            cout<<"Enter bonus: ";
            cin>>bonus;
        }
        void display(){
            //employee::display();
            cout<<"manager bonus is: "<<this->bonus<<endl;
        }
        protected:
        void display_Manager(){
            cout<<"Manager bonus is: "<<this->bonus<<endl;
        }
        void accept_Manager(){
            employee::display();
            cout<<"Manager bonus is: "<<this->bonus<<endl;

        }

};

class salesman: virtual public employee{
    private:
        float comm;
    public:
        salesman(){
            cout<<"salesman ctor(less)"<<endl;
            this->comm = 0;
        }
        salesman(float comm){
            cout<<"salesman ctor"<<endl;
            this->comm = comm;
        }

};

class sales_manager:public manager,public salesman{
    public:
        sales_manager(){
            cout<<"salesManager ctor(less)"<<endl;

        }
        sales_manager(int id,float bonus,float comm,float salary){
            cout<<"salesmanager ctor"<<endl;
        }

};


int main(){

    //employee e1;
    //manager m1;
    salesman s1;

    sales_manager sm1;
    return 0;
}