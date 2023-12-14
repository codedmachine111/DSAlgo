#include <iostream>
using namespace std;

class Student{
    public:
        double marks;

        Student(int marks){
            this->marks = marks;
        }
};

class Numbers{    
    public:
        int x;
        Numbers(int num){
            this->x = num;
        }
};

int calcSquare(const Numbers& number){
    return number.x*number.x;
}

double calcAvg(const Student& s1, const Student& s2){
            return (s1.marks + s2.marks)/2;
}

int main(){
    Student s1 = Student(10);
    Student s2 = Student(20);

    Numbers n1 = Numbers(10);

    double avg = calcAvg(s1,s2);
    cout << "Average: " << avg << endl;

    int square = calcSquare(n1);
    cout << "Square: " << square << endl;
    
    return 0;
}