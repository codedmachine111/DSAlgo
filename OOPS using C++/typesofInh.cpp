#include <iostream>
using namespace std;
// 1. Single Inheritance: 1 base class (Animal), 1 derived class (Dog)
// 2. Mutiple Inheritance: multiple base class (Animal), 1 derived classes
// 3. Multilevel Inheritance: Parent class dervied from another Parent class and then a derived class
// 4. Hierarchial Inheritance: like a tree of inheritance
class Animal{
    protected:
        void eat(){
            cout << "Eat" << endl;
        }
        void sleep(){
            cout << "Sleep" << endl;
        }
};

class Mammal{
    protected:
        void giveMilk(){
            cout << "Gives milk" << endl;
        }
};

class Dog:Animal{
    public:
        void bark(){
            cout << "Bark!!" << endl;
        }
        void routine(){
            eat();
            sleep();
            bark();
        }
};

class Monkey: Animal, Mammal{
    public:
        void routine(){
            eat();
            sleep();
            giveMilk();
        }
};

int main(){
    Dog dog1;
    Monkey m1;

    m1.routine();

    return 0;
}