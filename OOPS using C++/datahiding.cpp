#include <iostream>
using namespace std;
// Encapsulation
// 1. Information hiding
// 2. Data protection


class Employee{
    private:
        int salary;
        int id;
        string name;
    public:
        void setSalary(int s){
            this->salary = s;
        }
        void setId(int i){
            this->id = i;
        }
        void setName(string n){
            this->name = n;
        }

        void getData(){
            cout << this->id << " " <<  this->name << " " << this->salary << endl;
        }
};

int main(){
    Employee e1;

    e1.setId(1);
    e1.setName("John");
    e1.setSalary(10000);

    e1.getData();
    
    return 0;
}