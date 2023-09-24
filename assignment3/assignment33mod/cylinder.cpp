#include "./cylinder.h"

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