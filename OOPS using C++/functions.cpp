#include <iostream>
using namespace std;

class Human{
    public:
        int age;
        string name;
        // Inside class function
        void printData(){
            cout << age << " " << endl;
        }
        void printName();
};

void Human::printName(){
    cout << name << " " << endl;
}

int main(){
    Human john;
    john.age = 25;
    john.printData();

    john.name = "john";
    john.printName();
    return 0;
}