#include <iostream>
using namespace std;

class Student{
    public:
        int id;
        char CGPA;

        Student(int i, char g){
            this->id = i;
            this->CGPA = g;
        }

        void getDetails(){
            cout << this->id << " " << this->CGPA << endl;
        }  

        ~Student(){
            cout << "Freed!" << endl;
        }; 
};

int main(){
    Student s1 = Student(1,'A');
    Student s2 = Student(2,'C');

    s1.getDetails();
    s2.getDetails();

    return 0;
}