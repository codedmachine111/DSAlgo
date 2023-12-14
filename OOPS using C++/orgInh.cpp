#include <iostream>
using namespace std;

class Organisation{
    static int n_emps;
    private:
        string name;
    public:
        void setOrgName(string name){
            this->name = name;
        }

        string getOrgName(){
            return this->name;
        }

        static int getTotalEmployees(){
            return n_emps;
        }
};

class Employee:public Organisation{
    private:
        string emp_name;
        float salary;
    public:
        void setEmpInfo(string name, float salary){
            this->emp_name = name;
            this->salary = salary;
        }

        void printEmpInfo(){
            cout << this->emp_name << endl;
            cout << this->salary << endl;
        }
};

class Developer: public Employee{
    public:
        void getProjects(){
            cout << "Projects" << endl;
        }
};

int Organisation::n_emps = 10;

int main(){

    Developer d1;

    d1.setOrgName("Apple");
    d1.setEmpInfo("John", 100000.2);

    d1.getOrgName();
    d1.printEmpInfo();

    int n_emp = Organisation::getTotalEmployees();
    cout << "Number of employees: " << n_emp;
    
    return 0;
}