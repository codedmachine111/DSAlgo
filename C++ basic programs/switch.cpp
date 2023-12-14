#include <iostream>
using namespace std;

int main(){
    int day;
    cout << "Enter the day : \n";
    cin >> day;

    switch(day){
        case 1:
            cout << "Monday";
            break;
        default:
            cout << "Not a valid day";
            break;
    }

    return 0;
}