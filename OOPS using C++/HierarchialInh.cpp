#include <iostream>
using namespace std;

// More than one derived class is created from a single base class
class Humans{
    private:
        int age;
        float bp;
    public:
        void sleep(){
            cout << "Sleep" << endl;
        }

        void eat(){
            cout << "Eat" << endl;
        }
};

class Male:Humans{
    public:
        void becomeDad(){
            cout << "YOURE A DAD!!!" << endl;
        }
        void routine(){
            eat();
            sleep();
            becomeDad();
        }
};

class Female:Humans{
    public:
        void giveBirth(){
            cout << "Giving birth.." << endl;
        }
        void routine(){
            eat();
            sleep();
            giveBirth();
        }
};

int main(){
    Male m1;
    Female f1;

    m1.routine();
    
    return 0;
}