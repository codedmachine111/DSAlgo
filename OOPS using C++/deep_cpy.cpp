#include <iostream>
using namespace std;

// Deep copy

class Sample{
    private:
        int *p;
        int a,b;

    public:
        Sample(){
            p = new int;
        }
        Sample(Sample &other){
            this->a = other.a;
            this->b = other.b;
            p = new int(*other.p);
        }

        void setData(int a, int b, int p){
            this->a = a;
            this->b = b;
            *this->p = p;
        }

        void showData(){
            cout << "a: " << this->a << endl;
            cout << "b: " << this->b << endl;
            cout << "p addr: " << this->p << endl;
            cout << "p value: " << *this->p << endl;
        }
};

int main(){
    Sample s1;
    s1.setData(10,20,30);
    s1.showData();

    Sample s2=s1;
    s2.showData();

    // Address of p will be different (After copying)
    return 0;
}