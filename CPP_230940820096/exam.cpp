#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

class productException{
    private:
        int error_code;
        string message;
    public:
        productException(){
            this->error_code = 1000;
            this->message = "Something Went Wrong";
        }
        productException(int error_code,string message){
            this->error_code = error_code;
            this->message = message;
        }
        void display(){
            cout<<"Error code: productException"<<endl;
            cout<<"ERROR CODE: "<<this->error_code<<" Message: "<<this->message<<endl;
        }
};
class Product                                         //Base or Parent Class
{
private:
    /* data */
    string name;
    int price;
public:
    Product(){                                         //parameterless constructor
        this->name = "watch";
        this->price = 1;
    }
    Product(string name,int price){                    //parameterized constructor
        this->name = name;
        this->price = price;
    }
    virtual void accept(){                              //member function made as virtual so can access to child class member
        cout<<"Enter Product Name: ";                   //member function is possible
        cin>>this->name;
        cout<<"Enter Product Price: ";
        cin>>this->price;
        if(price <= 0)
            throw productException(1001,"Price cannot be zero or less than zero");
    }
    virtual void display(){
        cout<<"Product Name: "<<this->name<<endl;
        cout<<"Product Price: "<<this->price<<endl;
    }

    //getters
    string getName(){
        return this->name;
    }
    int getPrice(){
        return this->price;
    }

    //setters
    void setName(string name){
        this->name = name;
    }
    void setPrice(int price){
        this->price = price;
    }
    //destructor
    ~Product(){

    }
};
//hierarichal inheritance
class BasicWatch: virtual public Product{            //Derived or child class
    private:
        string dial;
        Product p;
    public:
        BasicWatch(){                                //parameterless constructor
            this->dial = "";
        }
        BasicWatch(string dial){                     //parameterized constructor
            this->dial = dial;
        }
        void accept(){                               
            Product::accept();                       //base class accept method using class name and scope resolution method
            cout<<"Enter type of dial: ";
            cin>>this->dial;
        }
        void display(){   
            cout<<"***********************************"<<endl;                          
            Product::display();                        //base class display method using class name and scope resolution method
            cout<<"Watch dial is of "<<this->dial<<" shape"<<endl;
            cout<<"***********************************"<<endl;
        }

        void writeIntoFile(BasicWatch &b){
            ofstream fout("BasicWatch.txt", ios::app);
            //fout <<b.getName()<< "," << b.getPrice() << "," <<b.getDial() <<endl;
            fout<<"***********************************"<<endl;
            fout<<"Name: "<<b.getName()<<endl;
            fout<<"Price: "<<b.getPrice()<<endl;
            fout<<"Dial Shape: "<<b.getDial()<<endl;
            fout<<"***********************************"<<endl;
            fout.close();
        }

        //getters
        string getDial(){
            return this->dial;
        }

        //setters
        void setDial(string dial){
            this->dial = dial;
        }

        //destructor
        ~BasicWatch(){

        }

};
//hierarichal inheritance
class SmartWatch: virtual public Product{      //Derived or child class
    private:
        string os;
        int battery;
    public:
        SmartWatch(){                          //parameterless constructor
            this->os = "";
            this->battery = 10;
        }
        SmartWatch(string os,int battery){      //parameterized constructor
            this->os = os;
            this->battery = battery;
        }
        void accept(){
            Product::accept();                   //base class accept method using class name and scope resolution method
            cout<<"Enter smart watch operating system: ";
            cin>>this->os;
            cout<<"Enter battery power: ";
            cin>>this->battery;
            if(battery <= 0)
                throw productException(1002,"Battery cannot be zero or less than zero");
        }

        void display(){
            cout<<"***********************************"<<endl;
            Product::display();                  //base class display method using class name and scope resolution method
            cout<<"Smart watch operating system is: "<<this->os<<endl;
            cout<<"Smart watch battery power is: "<<this->battery<<" MAH"<<endl;
            cout<<"***********************************"<<endl;
        }

        void writeIntoFile(SmartWatch &s){
            ofstream fout("SmartWatch.txt", ios::app);
            //fout <<s.getName()<< "," << s.getPrice() << "," <<s.getOS() << "," <<s.getBattery()<<endl;
            fout<<"***********************************"<<endl;
            fout<<"Name: "<<s.getName()<<endl;
            fout<<"Price: "<<s.getPrice()<<endl;
            fout<<"Operating System: "<<s.getOS()<<endl;
            fout<<"Batter: "<<s.getBattery()<<" MAH"<<endl;
            fout<<"***********************************"<<endl;
            fout.close();
        }


        //getters

        string getOS(){
            return this->os;
        }
        int getBattery(){
            return this->battery;
        }

        //setters

        void setOS(string os){
            this->os = os;
        }

        void setBattery(int battery){
            this->battery = battery;
        }

        //destructor
        ~SmartWatch(){

        }
};

int menu(){                                                   //menu list for menu driven program
    int choice;
    cout<<"**************************"<<endl;
    cout<<"0.EXIT."<<endl;
    cout<<"1. ADD BASIC WATCH."<<endl;
    cout<<"2. ADD SMART WATCH."<<endl;
    cout<<"3. DISPLAY COUNT OF BASIC AND SMART WATCHES."<<endl;
    cout<<"4. DISPLAY ALL PRODUCTS."<<endl;
    cout<<"5. DISPLAY ALL BASIC WATCHES."<<endl;
    cout<<"6. DISPLAY ALL SMART WATCHES."<<endl;
    cout<<"ENTER YOUR CHOICE: "<<endl;
    cin>>choice;
    cout<<"**************************"<<endl;
    return choice;
}

int main(){
    int choice;
    vector<Product* >ProductList;               //used vector for storing product information
    int BasicWatchCount = 0;                    //initial basic watch count
    int SmartWatchCount = 0;                    //initial basic watch count
    BasicWatch *b;
    SmartWatch *s;
    while((choice = menu()) != 0){              //menu driven code for multiple options
        switch(choice){
            case 1:
                try{
                    b = new BasicWatch();      
                    b->accept();
                    BasicWatchCount++;
                    ProductList.push_back(b);
                    b->writeIntoFile(*b);
                }catch(productException p){
                    p.display();
                }
                break;
            case 2:
                try{
                    s = new SmartWatch();
                    s->accept();
                    SmartWatchCount++;
                    ProductList.push_back(s);
                    s->writeIntoFile(*s);
                }catch(productException p){
                    p.display();
                }
                break;
            case 3:
                cout<<"Count of basic watches: "<<BasicWatchCount<<endl;
                cout<<"Count of smart watches: "<<SmartWatchCount<<endl;
                break;
            case 4:
                for(int i = 0 ; i < ProductList.size(); i++){
                    ProductList.at(i)->display();
                }
                break;
            case 5:
                for(int i = 0 ; i < ProductList.size(); i++){
                    if(typeid(*ProductList.at(i)) == typeid(BasicWatch)){       //used typeid for checking the type at runtime
                        ProductList.at(i)->display();
                    }
                }
                break;
            case 6:
                for(int i = 0 ; i < ProductList.size(); i++){
                    if(typeid(*ProductList.at(i)) == typeid(SmartWatch)){        //used typeid for checking the type at runtime
                        ProductList.at(i)->display();
                    }
                }
                break;
            default:
                cout<<"Wrong choice entered....."<<endl;
                break;
        }
    }
    cout<<"Thank you for using"<<endl;
    return 0;
}

