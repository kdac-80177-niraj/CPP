#include<iostream>
using namespace std;

class Cylinder{
    private:
        double radius;
        double height;
        double volume;
    public:
        Cylinder(){
            this->radius = 1;
            this->height = 1;
            this->volume = 3.14*radius*radius*height;
        }
        Cylinder(double radius,double height){
            cout<<"Volume is: "<<3.14*radius*radius*height<<endl;
        }
        void getRadius(){
            cout<<"Enter radius: "<<this->radius<<endl;;
        }
        void setRadius(){
            cout<<"update radius: ";
            cin>>this->radius;
        }
        void getHeight(){
            cout<<"Enter height: "<<this->height<<endl;;
        }
        void setHeight(){
            cout<<"update height: ";
            cin>>this->height;
        }
        void getVolume(){
            this->volume = 3.14*radius*radius*height;
            cout<<"Volume is: "<<this->volume<<endl;
        }
        void printVol(){
            cout<<"Volume is: "<<this->volume<<endl;
        }

};

enum Emenu{
    EXIT,
    RADIUS,
    UPDATERAD,
    HEIGHT,
    UPDATEHEI,
    GETVOLUME,
    PRINTVOL,
};
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

int main(){
    class Cylinder c1;
    Emenu choice;
    while((choice = menu())!=EXIT){
        switch(choice){
            case EXIT:
                cout<<"Exiting.........."<<endl;
                break;
            case RADIUS:
                c1.getRadius();
                break;
            case UPDATERAD:
                c1.setRadius();
                break;
            case HEIGHT:
                c1.getHeight();
                break;
            case UPDATEHEI:
                c1.setHeight();
                break;
            case GETVOLUME:
                c1.getVolume();
                break;
            case PRINTVOL:
                c1.printVol();
                break;
            default:
                cout<<"Wrong choice........."<<endl;
        }
    }

    return 0;
    cout<<"thank you"<<endl;
}