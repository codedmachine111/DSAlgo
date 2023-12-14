#include <iostream>
using namespace std;

int main(){
    cout << "Enter age: ";
    int age;
    cin >> age;

    if (age >18 && age <100){
        cout << "Can watch this movie!";
    }else{
        cout << "Cannot watch this movie!";
    }

    return 0;
}