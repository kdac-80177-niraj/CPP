#include<iostream>
using namespace std;

class Time{

    private:
        int hr,min,sec;
    public:
        Time(){
            this->hr = 0;
            this->min = 0;
            this->sec = 0;
        }
        Time(int hr,int min,int sec){
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }
        void acceptTime(){
            cout<<"Enter hour: ";
            cin>>this->hr;
            cout<<"Enter min: ";
            cin>>this->min;
            cout<<"Enter sec: ";
            cin>>this->sec;
        }
        void displayTime(){
            cout<<"Hour: "<<this->hr<<endl;
            cout<<"Min: "<<this->min<<endl;
            cout<<"Sec: "<<this->sec<<endl;
        }
        void getHour(){
            cout<<"Current Hour: "<<this->hr<<endl;
        }
        void getMin(){
            cout<<"Current Min: "<<this->min<<endl;
        }
        void getSec(){
            cout<<"Current Min: "<<this->sec<<endl;
        }
        void printTime(){
            cout<<"current time is: "<<this->hr<<":"<<this->min<<":"<<this->sec<<endl;
        }

        void setHr(){
            cout<<"Change Hour: "<<endl;
            cin>>hr;
        }
        void setMin(){
            cout<<"Change Min: "<<endl;
            cin>>min;
        }
        void setSec(){
            cout<<"Change Seconds: "<<endl;
            cin>>sec;
        }

        
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    Time **arr = new Time*[size];
    //on stack loc    //on heap loc
    //dynamic memory allocation for objects
    for(int i = 0;i<size;i++){
        arr[i] = new Time();
    }

    //keeping values in the array of objects
    for(int i = 0 ; i < size ; i++){
        cout<<"Enter values for index "<< i << " = " <<endl;
        arr[i] -> acceptTime();
    }
    //displaying the objects
    for(int i = 0 ; i < size ; i++){
        cout<<"values at index:  "<< i << " = " <<endl;
        //cout<<"value add of arr[" << i <<"] is: "<<&*arr[i]<<endl;
        arr[i] -> displayTime();
    }
    //for deallocating objects memory
    for(int i = 0 ; i < size ; i++){
        delete arr[i];
    }
    delete[] arr;

    //array of objects
    /*Time arr[5];

    for(int i = 0 ; i < 5 ; i++){
        cout<<"Enter the values of Time,min,sec for index "<<i<<" = "<<endl;
        arr[i].acceptTime();
    }

    for(int i = 0; i<5;i++){
        cout<<"values at index "<< i << " = " <<endl;
        arr[i].displayTime();
    }*/
    return 0;
}