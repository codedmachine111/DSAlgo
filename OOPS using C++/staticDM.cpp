#include <iostream>
using namespace std;

class Employee{
    

    public:
        static int x;
        
        static int increment(){
            return x=x+1;
        }
};

int Employee::x = 10;

int main(){
    Employee e1;

    cout << Employee::x << endl;

    // int inc = e1.increment();
    // cout << inc << endl;
    // cout << e1.increment() << endl;

    Employee::x++;
    cout << Employee::x++ << endl;
    
    return 0;
}