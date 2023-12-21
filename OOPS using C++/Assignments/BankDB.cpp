#include <iostream>
#include <iomanip>
using namespace std;

class Account{
    private:
        int id;
        string holderName;
        float balance;

    public:
        // Parameterized constructor
        Account(int id, string name, float bal){
            this->id = id;
            this->holderName = name;
            this->balance = bal;
        }

        // Copy constructor
        Account(Account &a){
            this->id = a.id;
            this->holderName = a.holderName;
            this->balance = a.balance;
        }

        void displayDetails(){
            cout << "ID: " << left << setw(10) << this->id<< endl;
            cout << "Name: " << left << setw(10) << this->holderName<< endl;
            cout << "Balance: " << left << setw(10) << this->balance<< endl;
            cout << endl;
        }

};

int main(){ 
    Account acc1(1,"John", 1000);
    Account acc2(2,"Jared", 300.90);

    Account acc3(acc2);

    acc1.displayDetails();
    acc2.displayDetails();
    acc3.displayDetails();

    return 0;
}