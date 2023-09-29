#include<iostream>
using namespace std;

class sell{
    public:
        virtual void accept() = 0;
        virtual void display() = 0;
        virtual int getPrice() = 0;

        /*float getPrice(){
            return this->bill;
        }*/


};

class book:public sell{
    private:
        int id;
        string title;
        string author;
        float price;
        int discount;
    public:
        void accept(){
            cout<<"Enter book id: ";
            cin>>id;
            cout<<"Enter book title: ";
            cin>>title;
            cout<<"Enter book author: ";
            cin>>author;
            cout<<"Enter book price: ";
            cin>>price;
        }
        void display(){
            cout<<"Book id: "<<this->id<<endl;
            cout<<"Book title: "<<this->title<<endl;
            cout<<"Book author: "<<this->author<<endl;
            cout<<"Book price: "<<this->price<<endl;
        }
        int getBookId(){
            return this->id;
        }
        string getBooktitle(){
            return this->title;
        }
        string getBookAuthor(){
            return this->author;
        }
        int getPrice(){
            return this->price;
        }

        
};

class tape: public sell{
    private:
        int id;
        string title;
        string artist;
        float price;
    public:
        void accept(){
            cout<<"Enter tape id: ";
            cin>>id;
            cout<<"Enter tape title: ";
            cin>>title;
            cout<<"Enter tape artist: ";
            cin>>artist;
            cout<<"Enter tape price: ";
            cin>>price;
        }
        void display(){
            cout<<"Tape id: "<<this->id<<endl;
            cout<<"Tape title: "<<this->title<<endl;
            cout<<"Tape author: "<<this->artist<<endl;
            cout<<"Tape price: "<<this->price<<endl;
        }
        int getTapeId(){
            return this->id;
        }
        string getTapetitle(){
            return this->title;
        }
        string getTapeArtist(){
            return this->artist;
        }
        int getPrice(){
            return this->price;
        }

};

int menu(){
    int choice;
    cout<<"******************************"<<endl;
    cout<<"0. EXIT."<<endl;
    cout<<"1. Buy a book."<<endl;
    cout<<"2. Buy a tape."<<endl;
    cout<<"3. Display all orders."<<endl;
    cout<<"4. calculate total bill."<<endl;
    cout<<"5. Enter choice: "<<endl;
    cin>>choice;
    return choice;
}
int main(){
    int choice;
    sell *s[3];
    int index = 0;
    float bill = 0;
    while((choice = menu()) != 0){
        switch(choice){
            case 1:
                if(index < 3){
                    s[index] = new book(); //upcasting
                    s[index]->accept();
                    index++;
                }
                else
                    cout<<"Order limit is full";
                break;
                
            case 2:
                if(index < 3){
                    s[index] = new tape(); //upcasting
                    s[index]->accept();
                    index++;
                }
                else
                    cout<<"Order limit is full";
                break;

            case 3:
                for(int i = 0 ; i < index ; i++ ){
                    cout<<"**********************"<<endl;
                        s[i]->display();
                    }
                    break;

            case 4: 
                for(int i = 0 ; i < index ; i++){
                    bill+=s[i]->getPrice(); 
                }
                cout<<"Bill till now is: "<<bill<<endl;
                break;
            default:
                cout<<"wrong choice......"<<endl;
                break;

        }
    }
    for(int i = 0 ; i < index ; i++)
        delete s[i];
    cout<<"Thank You For Shopping, Your Total Bill Is: "<<bill<<endl;
    return 0;
}

//cout<<"Bill till now is: "<<bill<<endl;
// if(i==index)
//cout<<"Bill= "<<bill<<endl; 