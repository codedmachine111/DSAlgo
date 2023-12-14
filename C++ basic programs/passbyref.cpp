#include <iostream>
using namespace std;

// pass by reference

void modifyString(string &s){
    s = 't';
}
int main(){
    string s = "This is a string";
    modifyString(s);
    cout << s;
    return 0;
}