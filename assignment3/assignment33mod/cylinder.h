#ifndef CYLINDER_H
#define CYLINDER_H
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

#endif
