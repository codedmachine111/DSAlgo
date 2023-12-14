#include <iostream>
using namespace std;

// name roll grade, read and display

class Student{
    public:
        string name;
        int roll;
        char grade;
        // Student(string n, int r, char g){
        //     name = n;
        //     roll = r;
        //     grade = g;
        // }

        void readData(string n, int r, char g){
            name = n;
            roll = r;
            grade = g;
        }

        void displayData(){
            cout << "Name : " << name << " " << "Roll : " << roll  << " " << "Grade : " << grade << endl;
        }
};


int main(){
    Student s[5];
    string name;
    int roll;
    char grade;

    for(int i=0; i<5; i++){
        cout << "Enter name : " << endl;
        cin >> name;
        cout << "Enter Roll : " << endl;
        cin >> roll;
        cout << "Enter grade : " << endl;
        cin >> grade;
        s[i].readData(name, roll, grade);
    }

    for(auto it : s){
        it.displayData();
    }

    return 0;
}