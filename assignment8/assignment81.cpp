#include<iostream>
using namespace std;

class Distance{
    private:
        float feet;
        float inch;
    public:
        Distance(){
            this->feet = 1;
            this->inch = 12;
        }
        Distance(float feet,float inch){
            this->feet = feet;
            this->inch = inch;
        }
        void calFeet(int inch){
            this->feet = inch/12;
        }
        void calInch(int feet){
            this->inch = feet*12;
        }
        void display(){
            cout<<"Feets " << this->feet << " equals to " << this->inch << " inches.."<<endl;
        }
        void displayInch(){
            cout<<"current total inches are: "<<this->feet*12+this->inch<<endl;
        }
        void displayFeet(){
            cout<<"current total feets are: "<<this->feet+this->inch/12<<endl;
        }
        float GetInch(){
            return this->inch;
        }
        float GetFeet(){
            return this->feet;
        }
        Distance operator+(Distance d2){
            Distance result;
            result.feet = this->feet+d2.feet;
            result.inch = this->inch+d2.inch;
            return result;
        }
        float &operator++(){
            inch++;
            return inch;
        }
        /*float &operator--(){
            inch--;
            return inch;
        }*/
        friend bool operator==(Distance d1,Distance d2); 
        friend Distance operator--(Distance d);

        friend void operator << (ostream &out,Distance &d);
        friend void operator >>(istream &in,Distance &d);

};
void operator << (ostream &out,Distance &d){
    out<<"Feets: "<<d.feet<<"Inches: "<<d.inch<<endl;
}

void operator >>(istream &in,Distance &d){
    cout<<"Enter Feets: "<<endl;
    in>>d.feet;
    cout<<"Enter Inches: "<<endl;
    in>>d.inch;
}

/*Distance operator++(Distance d){
    Distance r;
    r.feet = d.feet;
    r.inch = d.inch+1;
    return r;
}*/
Distance operator--(Distance d){
    Distance r;
    r.feet = d.feet;
    r.inch = d.inch-1;
    return r;
}
bool operator == (Distance d1,Distance d2){
    if(d1.feet == d2.feet && d1.inch == d2.inch){
        return true;
    }else{
        return false;
    }
}

int main(){
    Distance d1(2,24);
    Distance d2(3,36);
    Distance d3 = d1+d2;
    if(d1 == d2){
        cout<<"Equal Distance"<<endl;
    }else{
        cout<<"Not Equal"<<endl;
    }
    d3.display();
    // ++d3;
    // d3.display();
    Distance d4 = --d3;
    //d4.display();
    cout<<d4;
    Distance d5;

    cout<<"Enter new object"<<endl;
    cin>>d5;

    return 0;
}