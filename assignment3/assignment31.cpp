#include<iostream>
using namespace std;

class Box{
    private:
        int length,width,height;
    public:

        Box(){
            this->length = 1;
            this->width = 1;
            this->height = 1;
        }
        void addDimensions(){
            cout<<"Enter Length: ";
            cin>>this->length;

            cout<<"Enter Width: ";
            cin>>this->width;

            cout<<"Enter Height: ";
            cin>>this->height;
        }
        void calVolume(){
            int volume = length*width*height;
            cout<<"Volume is: "<<volume<<endl;
        }
};

enum EmenuList{
    EXIT,
    DIMENSIONS,
    VOLUME
};
EmenuList menu(){
    int choice;
    cout<<"**************************"<<endl;
    cout<<"0. Exit."<<endl;
    cout<<"1. Add dIMENSIONS: "<<endl;
    cout<<"2. Find Volume:  "<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>choice;
    cout<<"**************************"<<endl;
    return EmenuList(choice);
}

int main(){
    class Box b1;
    EmenuList choice;
    while ((choice = menu()) != EXIT){
        switch(choice){
            case EXIT:
                cout<<"Exiting......"<<endl;
                break;
            case DIMENSIONS:
                b1.addDimensions();
                break;
            case VOLUME:
                b1.calVolume();
                break;
            default:
                cout<<"Wrong choice entered!!!!!!"<<endl;
                break;
        }
    }
    cout<<"Thank you for choosing.....";
    return 0;
}