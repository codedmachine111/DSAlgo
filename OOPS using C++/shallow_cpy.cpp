#include <iostream>
using namespace std;

// Deep copy:    Dynamically allocated memory for the copy, and then copies the values of varibales.
//               This was the source and copy do not share the same memeory location. requires us to write user-defined constructor.
// Shallow copy: An object is created by simply copying the data of all variables of the original object. 
//               This was the source and copy will share the same memeory location.

class Sample{
    private:
        int *p;
        int a,b;

    public:
        Sample(){
            p = new int;
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

    // Address of p will be same (After copying)
    return 0;
}