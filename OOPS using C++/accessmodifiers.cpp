#include <iostream>
using namespace std;

class A{
    private:
        int x=100;
    public:
        int y=10;
        void func(){
            cout << x << endl;
        }
};

class B:A{
    public:
        void printNum(){
            cout << A::y << endl;
        }
};

int main(){
    A a;
    B b;

    a.func();
    b.printNum();

    return 0;
}