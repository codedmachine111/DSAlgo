#include <iostream>
#include <string.h>
using namespace std;

void swap(string &str, int a, int b){
    char temp = str[a];
    str[a] = str[b];
    str[b] = temp;
}

void swapInt(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void findsize(int a, float b, bool c){
    int sizeInt = sizeof(a);
    int sizeFloat = sizeof(b);
    int sizeBool = sizeof(c);

    cout << sizeInt << " " << sizeFloat << " " << sizeBool << endl;

}

pair<int,int> areaAndPerimeter(float length, float breadth){
    float area = length * breadth;
    float perimeter = 2 * (length+breadth);
    return {area, perimeter};
}

string reverseString(string &str){
    int start =0;
    int end = str.size()-1;
    int mid = start + (end-start)/2;
    for(int i=0; i<=mid; i++){
        swap(str,start,end);
        start++;
        end--;
    }
    return str;
}

void reverseStringRecursion(string &str, int start, int end){
    if(start==end){
        return;
    }
    swap(str,start,end);
    reverseStringRecursion(str, start+1, end-1);
}

int main(){
    string str1, str2, str3="", str4;
    cout << "Enter a string: " << endl;
    getline(cin, str1);

    // Length of string
    cout << "Length of string is : " << strlen(&str1[0]) << endl;
    
    cout << "Enter second string : "<< endl;
    getline(cin, str2);

    // Compare two strings
    if(strcmp(&str1[0],&str2[0])==0){
        cout << "The strings are equal!" << endl;
    }else{
        cout << "The strings are not equal" << endl;
    }
    
    
    // Copy a string
    strcpy(&str3[0],&str1[0]);
    cout << "The copied string is : " << str3 << endl;

    // Concat two strings
    cout << "The concatinated string is : " << strcat(&str1[0],&str2[0]) << endl;

    // Reverse a string
    reverseStringRecursion(str1,0,str1.size()-1);
    cout << "The reversed string is : " << str1 << endl;

    findsize(1,1.1,true);
    return 0;
}