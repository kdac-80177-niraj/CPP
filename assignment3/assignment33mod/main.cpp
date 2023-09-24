#include "./cylinder.h"
#include "./menu.h"

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
