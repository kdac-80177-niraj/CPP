#include<iostream>
using namespace std;

class ToolBooth{
    private:
        double cash;
        unsigned int totalCars;
    public:
        ToolBooth(){
            this->cash = 0;
            this->totalCars = 0;
        }

        void payingCar(){
            totalCars++;
            cash += 0.50;
        }
        void nopayCar(){
            totalCars++;
        }
        void printOnConsole(){
            int payCar = this->cash*2;
            cout<<"Total cars paased: "<<this->totalCars<<endl;
            cout<<"Total ammount collected: "<<this->cash<<endl;
            cout<<"Total cars that paid: "<<payCar<<endl;
            cout<<"Total cars that not payed: "<<this->totalCars-payCar<<endl;
        }
};

enum Emenu{
    EXIT,
    PAYING,
    NONPAYING,
    PRINT
};
Emenu menu(){
    int choice;
    cout<<"****************************"<<endl;
    cout<<"0. EXIT"<<endl;
    cout<<"1. Paying cars"<<endl;
    cout<<"2. Non paying cars"<<endl;
    cout<<"3. Print on console"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    cout<<"****************************"<<endl;
    return Emenu(choice);
}
int main(){
    ToolBooth t1;
    Emenu choice;
    while((choice = menu()) != EXIT){
        switch(choice){
            case EXIT:
                cout<<"Exiting........"<<endl;
                break;
            case PAYING:
                t1.payingCar();
                break;
            case NONPAYING:
                t1.nopayCar();
                break;
            case PRINT:
                t1.printOnConsole();
                break;
            default:
                cout<<"wrong choice"<<endl;
        }
    }
    cout<<"thank you"<<endl;
    return 0;
}