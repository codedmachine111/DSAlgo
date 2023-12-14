#include <iostream>
#include <vector>
using namespace std;

class Student{
    private:
        // Private Data members
        int id;
        string name;
        float cgpa;
        int attendance;
        
        // const data member
        const int courses=10;

    public: 
        // Static data member
        static int totalStudents;      

        // Constructor
        Student(int id, string name, float cgpa, int att){
            this->id = id;
            this->name = name;
            this->cgpa = cgpa;
            this->attendance = att;
        }

        // Simple member function
        void setAttendance(int attn){
            this->attendance = attn;
        }
        int getAttendance(){
            return this->attendance;
        }

        // Static member functions
        static void dispTotalStudents(){
            cout << "Total students are: " << totalStudents << endl;
        }
        
        // Inline member functions
        inline void printCGPA(){
            cout << this->name << "'s " << "CGPA: " << this->cgpa << endl;
        }

        // Const member functions
        const int getCourses(){
            return courses;
        }

        // Friend
        void displayInfo(const Student& student);
};

int Student::totalStudents = 2;

void Student::displayInfo(const Student& student){
    cout << "ID : " << this->id << endl;
    cout << "Name : " << this->name << endl;
    cout << "CGPA : " << this->cgpa << endl;
}

int main(){
    vector<Student> studentDB;

    studentDB.emplace_back(Student(1,"Raju",9.2,82));
    studentDB.emplace_back(Student(2,"Shyaam",4.5,23));

    Student::dispTotalStudents();

    for(int i=0; i<Student::totalStudents; i++){
        studentDB[i].displayInfo(studentDB[i]);
    }

    for(int i=0; i<Student::totalStudents; i++){
        studentDB[i].printCGPA();
        int courses = studentDB[i].getCourses();
        cout << "Courses :" << courses << endl;
        int attend = studentDB[i].getAttendance();
        cout << "Attendance :" << attend << endl;
    }

    return 0;
}