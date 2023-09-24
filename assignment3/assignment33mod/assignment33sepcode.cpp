#include<iostream>
using namespace std;

class Cylinder{
    private:
        double radius;
        double height;
        double volume;
    public:
        Cylinder();
        void getRadius();
        void setRadius();
        void getHeight();
        void setHeight();
        void getVolume();
        void printVol();
};

Cylinder :: Cylinder(){
    this->radius = 1;
    this->height = 1;
    this->volume = 3.14*radius*radius*height;
}
/*Cylinder::Cylinder(double radius,double height){
    cout<<"Volume is: "<<3.14*radius*radius*height<<endl;
}*/
void Cylinder:: getRadius(){
    cout<<"Enter radius: "<<this->radius<<endl;;
}

void Cylinder:: setRadius(){
    cout<<"update radius: ";
    cin>>this->radius;
}

void Cylinder:: getHeight(){
    cout<<"Enter height: "<<this->height<<endl;;
}

void Cylinder:: setHeight(){
    cout<<"update height: ";
    cin>>this->height;
}

void Cylinder:: getVolume(){
    this->volume = 3.14*radius*radius*height;
    cout<<"Volume is: "<<this->volume<<endl;
}

void Cylinder:: printVol(){
    cout<<"Volume is: "<<this->volume<<endl;
}

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

