#include<iostream>
using namespace std;

class Address{
private:
    string building;
    string street;
    string city;
    int pin;

public:

//constructor 
    Address(){
        this->building = "Sunbeam";
        this->street = "Shaniwar peth";
        this->city = "Karad";
        this->pin = 415110;
    }

//Parameterized constructor 
    Address(string building,string street,string city,int pin){
        this->building = building;
        this->street = street;
        this->city = city;
        this->pin = pin;
    }

    //accept
    void accept(){
        cout<<"Enter Building Name: ";
        cin>>this->building;

        cout<<"Enter Street Name: ";
        cin>>this->street;

        cout<<"Enter City Name: ";
        cin>>this->city;

        cout<<"Enter PIN Name: ";
        cin>>this->pin;
    }

    //display
    void display(){
        cout<<"Building name is: "<<building<<endl;
        cout<<"Street Name is: "<<street<<endl;
        cout<<"City name is: "<<city<<endl;
        cout<<"PIN is: "<<pin<<endl;
    }

    //getters
    string getBuilding(){
        return this->building;
    }
    string getStreet(){
        return this->street;
    }
    string getCity(){
        return this->city;
    }
    int getPIN(){
        return this->pin;
    }

    //setters
    void setBuilding(string building){
        this->building = building;
    }
    void setStreet(string getStreet){
        this->street = street;
    }
    void setCity(string city){
        this->city = city;
    }
    void setPIN(int pin){
        this->pin = pin;
    }
};

int main(){
    //Address add("B-8","blueRidge","Hinjewadi",411057);
    //add.display();
    Address add;
    add.setPIN(415313);
    add.display();
    //return 0;

    cout<<"pin in: "<< add.getPIN()<<endl;
    return 0;

}