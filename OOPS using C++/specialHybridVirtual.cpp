#include <iostream>
using namespace std;

class A{
    public:
        A(){
            cout << "this is class A" <<endl;
        }
};

// Virtual base class
class B: public A{
    public:
        int b;

        B(){
            cout << "this is class B" << endl;
        }
};

// Virtual base class
class C: public A{
    public:
        int c;

        C(){
            cout << "this is class C" << endl;
        }
};

class D: public B, public C{
    public:
        int d;

        D(){
            cout << "this is class D" << endl;
        }
};

int main(){

    D obj1;

    // obj1.B::show();
    // obj1.show();


    return 0;
}
// vidyashri.math@kletech.ac.in