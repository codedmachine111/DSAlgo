#include <iostream>
using namespace std;

class Student{
    protected:
        int roll;
        float marks1, marks2;
    public:
        Student(int roll, float m1, float m2){
            this->roll = roll;
            this->marks1 = m1;
            this->marks2 = m2;
        }

        float getTotalStudentMarks(){
            return this->marks1 + this->marks2;
        }
};

class Project{
    protected:
        float p_marks;
    public:
        Project(float p){
            this->p_marks = p;
        }

        float getProjectMarks(){
            return this->p_marks;
        }
};

class Result: public Student, public Project{
    protected:
        int sm;
        int pm;
    public:
        Result(int roll, float m1, float m2, float p1): Student(roll, m1, m2), Project(p1){}
        float getTotalMarks(){
            this->sm = getTotalStudentMarks();
            this->pm = getProjectMarks();
            return this->sm+ this->pm;
        }
        float getAverage(){
            return (this->sm + this->pm)/3;
        }
        void displayInfo(){
            float total = getTotalMarks();
            float avg = getAverage();
            cout << "Total Marks: " << total << endl;
            cout << "Average: " << avg << endl;
        }
};

int main(){
    Result s1(1,15,20,70);

    s1.displayInfo();

    return 0;
}