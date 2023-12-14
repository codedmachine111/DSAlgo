#include <iostream>
using namespace std;

int main(){
    // TAKING INPUTS
    // int x,y;
    // cout << "Enter value of x and y: ";
    // cin >> x >> y;
    // cout << "Entered numbers: "<< x << " and " << y;

    // TAKING STRING INPUTS
    // string name, surname;
    // cout << "Enter full name: ";
    // cin >> name >> surname;
    // cout << "Name is : " << name << " "<< surname;

    // TAKING A LINE OF STRING
    string fullName;
    getline(cin, fullName);
    cout << fullName;

    return 0;
}