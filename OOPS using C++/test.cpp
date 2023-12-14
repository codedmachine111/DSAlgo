// Cpp program to illustrate working of object and class to
// find area a1nd volumne of room

#include <iostream>
using namespace std;

class myClass{
    public:
        int num;
        string str;

        int getSquare(int num){
            return num *num;
        }
};

class Parameters{
    public:
        int length;
        int breadth;
        int height;

        int getArea(int l, int b, int h){
            return (2*(l*b + b*h + l*h));
        }

        int getVolume(int l, int b, int h){
            return l*b*h;
        }

};

class Human{
    
    public:
        static int salary;
        static string company;
        int age;
        string name;

        Human(int x, string y){
            age = x;
            name = y;
        }

        void printJob(int s){
            cout << "Global Salary is : " << salary << endl;
            cout << "Local Salary is : " << s << endl;

        }

        void printDetails(int age, string name);
};

class A{
    protected:
        int x;
    public: 
        A(){
            x= 10;
        }
};

class B{
    protected:
        int x;
    public: 
        B(){
            x= 20;
        }
};

class C : public A, public B{
    public:
        void disp(){
            cout << "A's x : " << A::x << endl;
            cout << "B's x : " << B::x << endl;
        }
};

void Human::printDetails(int age, string name){
    cout << age << " " << name << endl;
}   

int  p;
int Human::salary = 100;

int main(){
    myClass obj;
    myClass obj2;
    Parameters room1;
    Human akash(21, "Akash");
    C c;
    c.disp();

    akash.printJob(1002);
    
    cout << akash.name << " " << akash.age << endl;
    // akash.printDetails(21, "AKash");

    // obj.num = 10;
    // obj.str = "Number is:";

    // obj2.num = 14;
    // obj2.str = "Number is:";

    // cout << obj.str << " " << obj.num << endl;
    // cout << obj2.str << " " << obj2.num << endl;

    // int sq = obj.getSquare(obj.num);
    // cout << sq << " ";

    room1.length = 10;
    room1.breadth = 10;
    room1.height = 2;

    int area = room1.getArea(room1.length, room1.breadth, room1.height);
    int volume = room1.getVolume(room1.length, room1.breadth, room1.height);

    cout << "Area is : " << area << endl << "Volume is : " << volume << endl;
    
    int p=10;

    cout << "Global p : " << ::p << endl;
    cout << "Local p : " << p;

    return 0;
}