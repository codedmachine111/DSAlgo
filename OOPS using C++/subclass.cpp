#include <iostream>
using namespace std;

class A{
    public:
        int num=69;
        class B{
            private:
                int num;
            public:
                void putData(int n){
                    num = n;
                }

                void getData(){
                    cout << "B's num is : " <<  num << endl;
                    // cout << "A's num is : " <<  A::num << endl;
                }
        };

};

class D: public A{
    public:
        void getAsData(){
            cout << A::num << endl;
        }
};

int main(){
    A::B obj;

    D d;
    d.getAsData();

    obj.putData(10);
    obj.getData();

    return 0;
}