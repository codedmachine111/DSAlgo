#include <iostream>
#include <string.h>
using namespace std;

class Student{
    private:
        int roll;
        string name;
        float gpa;
    public:
        // Default constructor
        Student(){
            this->roll=1;
            this->name="";
            this->gpa=0;
        }

        // Parameterized constructor
        Student(int roll, string name, float gpa){
            this->roll = roll;
            this->name = name;
            this->gpa = gpa;
        }

        // Copy constructor
        Student(Student &x){
            this->roll = x.roll;
            this->name = x.name;
            this->gpa = x.gpa;
        }

        void display(){
            cout << "Roll no: "<< this->roll << endl;
            cout << "Name: "<< this->name << endl;
            cout << "GPA: "<< this->roll << endl;
            cout << endl;
        }
};

int main(){
    Student A(1,"John",9.9);
    cout << addressof(A) << endl;
    // implicit call
    Student B(A);
    cout << addressof(B) << endl;
    // Explcit call
    Student C=A;
    cout << addressof(C) << endl;

    A.display();
    B.display();
    C.display();

    return 0;
}