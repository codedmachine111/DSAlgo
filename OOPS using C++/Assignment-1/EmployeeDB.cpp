#include <iostream>
#include <vector>
using namespace std;

class Employee{
    private:
        int id;
        string name;
        float salary;

        const int bonus=10;
    
    public:
        static string company;

        // Constructor
        Employee(int id, string name, float salary){
            this->id = id;
            this-> name = name;
            this->salary = salary;
        }
        // Simple
        int getId(){
            return id;
        }
        void setId(int id){
            this->id = id;
        }

        float calcSalaryAfterBonus() {
            return this->salary * (1 + bonus/100);
        }

        const int getBonus(int s){
            return bonus;
        }
        
        inline void dispSalary(){
            cout << "Salary of Employee: " << this->id << " " << this->salary << endl;
        }

        static void dispCompany(){
            cout << "Company: " << company << endl;
        }

        friend class Info;
};

class Info{
    public:
        void displayInfo(const Employee& employee){
            cout << "ID : " << employee.id << endl;
            cout << "Name : " << employee.name << endl;
            cout << "Salary : " << employee.salary << endl;
            cout << "Bonus : " << employee.bonus << endl;

            // float sal = employee.calcSalaryAfterBonus();
            // cout << "Salary after bonus : " << sal << endl;
        }
};

string Employee::company = "Apple";

int main(){
    Employee e1(1, "A", 1000);
    Employee e2(2, "B", 2000);
    Employee e3(3, "C", 3000);
    Employee e4(4, "D", 4000);
    Employee e5(5, "E", 5000);

    vector<Employee> employees;
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    employees.push_back(e4);
    employees.push_back(e5);

    Info f;
    for(int i=0; i<employees.size(); i++){
        f.displayInfo(employees[i]);
    }

    return 0;
}