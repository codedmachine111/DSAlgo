#include <iostream>
using namespace std;

class College{
    protected:
        string collName;
    public:
        College(string name){
            this->collName = name;
        }
        void printCollegeName(){
            cout << this->collName << endl;
        }
};

class Department{
    protected:
        string deptName;
    public:
        Department(string c_name){
            this->deptName = c_name;
        }
        void printDeptName(){
            cout << this->deptName << endl;
        }
};

class Student: public College, public Department{
    private:
        float cgpa;
        string s_name;
    public:
        Student(string name, float cgpa, string cname, string dname): College(cname), Department(dname){
            this->cgpa = cgpa;
            this->s_name = name;
        }

        void getStudentDetails(){
            printDeptName();
            printCollegeName();
            cout << this->s_name << endl;
            cout << this->cgpa << endl;
        }
};


int main(){
    
    Student s1("John", 9.9, "BVB", "ECE");
    s1.getStudentDetails();

    return 0;
}