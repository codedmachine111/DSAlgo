#include <iostream>
using namespace std;

class Vehicle{
    public:
        Vehicle(){
            cout << "This is a vehicle" << endl;
        }
};

class Fare{
    public:
        Fare(){
            cout << "This is Fare" << endl;
        }
};

class Car: public Vehicle{};

class Bus: public Vehicle, public Fare{
    public:
        Bus(){
            cout << "this is a bus";
        }
};

int main(){
    
    Bus b1;
    
    return 0;
}