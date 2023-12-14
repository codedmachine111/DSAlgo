#include <iostream>
using namespace std;

class A{
    public:
        int a;
};

class B: public A{
    public:
        int b;
};

class C: public A{
    public:
        int c;
};

class D: public B, public C{
    public:
        int d;
};

int main(){

    D obj1;

    obj1.B::a = 10;
    obj1.C::a = 20;

    obj1.b =30;
    obj1.c = 40;
    obj1.d = 50;

    cout << obj1.B::a << " " << obj1.C::a;

    return 0;
}