#include<iostream>
#include<vector>
using namespace std;

enum acc_type{
    SAVING,
    CURRENT,
    DMAT
};

class accountException{
    private:
        int error_code;
        string msg;
    public:
        accountException(){
            this->error_code = 1000;
            this->msg = "something went wrong";
        }
        accountException(int error_code,string msg){
            this->error_code = error_code;
            this->msg = msg;
        }
        void printError(){
            cout<<"Error::Account Errors"<<endl;
            cout<<"Error Code: "<<this->error_code<<endl;
            cout<<this->msg<<endl;
        }
};
class insufficient_funds{
    private:
        int accid;
        double cur_balance;
        double withdraw_amount;
    public:
        insufficient_funds(int accid,double cur_balance,double withdraw_amount){
            this->accid = accid;
            this->cur_balance = cur_balance;
            this->withdraw_amount = withdraw_amount;
        }
        void display(){
            cout<<"Account balance is less than min balance"<<endl;
            cout<<"Withdraw unsuccesfull"<<endl;
        }

};
class account{
    private:
        int id;
        acc_type type;
        double balance;
    public:
        account(){
            this->id = 0;
            this->balance = 0;
        }
        account(int id,acc_type type,double balance){
            this->id = id;
            type = type;
            balance = balance;
        }

        void accept(){
            int t;
            cout<<"Enter account id: ";
            cin>>this->id;
            if(id == 0)
                throw accountException(1001,"Account id can't be 0");
            cout<<"Enter account type: "<<endl;
            cout<<"1.SAVINGS"<<endl;
            cout<<"2.CURRENT"<<endl;
            cout<<"3.DMAT"<<endl;
            cin>>t;
            if(t == 0)
                acc_type type = acc_type::SAVING;
            if(t == 1)
                acc_type type = acc_type::CURRENT;
            if(t == 2)
                acc_type type = acc_type::DMAT;
            cout<<"Enter account balance: ";
            cin>>this->balance;
                if(balance < 500)
                    throw accountException(1002,"Account balance can't be less than 500");  
        }

        void display(){
            cout<<"Account number: "<<this->id<<endl;
            cout<<"Account type is: ";
            if( type== acc_type::SAVING)
                cout<<"SAVINGS"<<endl;
            if( type== acc_type::CURRENT)
                cout<<"CURRENT"<<endl;
            if( type== acc_type::DMAT)
                cout<<"DMAT"<<endl;
            cout<<"Account balance is: "<<this->balance<<endl;
        }
        
        void setId(int id){
            this->id = id;
        }
        void setType(int t){
            this->type = (acc_type)t;
        }
        int getId(){
            return this->id;
        }
        acc_type getType(){
            return type;
        }
        double getBalance(){
            return this->balance;
        }
        void deposit(int deposit){
            cout<<"Enter ammount to deposit: ";
            cin>>deposit;
            this->balance += deposit;
        }
        void withdraw(int bal){
            if(this->balance > bal){
                cout<<"Enter ammount to withdraw: ";
                cin>>bal;
                this->balance -= bal;
            }else
                throw insufficient_funds(id,balance,bal);
        }
};

int menu(){
    int choice;
    cout<<"***************************"<<endl;
    cout<<"0. EXIT."<<endl;
    cout<<"1. Accept new details."<<endl;
    cout<<"2. Deposit amount."<<endl;
    cout<<"3. Withdraw amount."<<endl;
    cout<<"4. Display account."<<endl;
    cout<<"***************************"<<endl;
    cin>>choice;
    return choice;
}

int main(){
    int choice;
    int acid;
    //account a[10];
    vector<account* >v1;
    int count = 0;
    int withdraw;
    int deposit;
    while((choice = menu())!=0){
        switch(choice){
            case 1:
                if(count<10){
                    account *aptr = new account();
                    aptr->accept();
                    v1.push_back(aptr);
                    //a->accept();
                    count++;
                }else{
                    cout<<"storage full"<<endl;
                }
                break;
            case 2:
                cout<<"Enter account id to deposit: ";
                cin>>acid;
                cout<<"Enter amount to deposit: "<<endl;
                cin>>deposit;
                //a->deposit(deposit);
                for(int i = 0 ; i < v1.size(); i++){
                    if(v1.at(i)->getId() == acid){
                        v1.at(i)->deposit(deposit);
                    }
                }
                break;
            case 3:
                try{
                    cout<<"Enter account id to withdraw: ";
                    cin>>acid;
                    cout<<"Enter amount you want to withdraw: ";
                    cin>>withdraw;
                    for(int i = 0 ; i < v1.size(); i++){
                        if(v1.at(i)->getId() == acid){
                            v1.at(i)->withdraw(withdraw);
                        }
                    }
                    //a->withdraw(withdraw);
                }catch(insufficient_funds error){
                    error.display();
                }
                break;
            case 4:
                cout<<"Enter your account number: ";
                cin>>acid;
                cout<<"Account Information is: "<<endl;
                //a->display();
                for(int i = 0 ; i < v1.size(); i++){
                    if(v1.at(i)->getId() == acid){
                        v1.at(i)->display();
                    }
                }

                break;
            default:
                cout<<"wrong choice entered"<<endl;
        }
    }
    return 0;
}