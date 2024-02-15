#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern3(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
}

void pattern4(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << i+1;
        }
        cout << endl;
    }
}

void pattern5(int n){
    for(int i=0; i<n; i++){
        for(int j=n-i-1;j>=0; j--){
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern6(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<=n-i-1; j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
}

void pattern7(int n){
    for(int i=0; i<n; i++){
        // print spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        // print stars
        for(int j=0; j<2*i+1; j++){
            cout << "*";
        }
        // print spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern8(int n){
    for(int i=0; i<n; i++){
        // print spaces
        for(int j=0; j<i; j++){
            cout << " ";
        }
        // print stars
        for(int j=0; j<(2*n-(2*i+1)); j++){
            cout << "*";
        }

        // print spaces
        for(int j=0; j<i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern9(int n){
    pattern7(n);
    pattern8(n);
}

void pattern10(int n){
    for(int i=1; i<=2*n-1; i++){
        int stars = i;
        if(i>n) stars = 2*n -i;
        for(int j=0; j<stars; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void pattern11(int n){
    for(int i=0; i<n; i++){
        int start =0;
        if(i%2==0) start =1;

        for(int j=0; j<=i; j++){
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

void pattern12(int n){
    int init_space = 2*(n-1);
    for(int i=1; i<=n; i++){
        // number
        for(int j=0; j<i; j++){
            cout << j+1;
        }
        // space
        for(int j=1; j<=init_space; j++){
            cout << " ";
        }
        // number
        for(int j=i; j>=1; j--){
            cout << j;
        }
        cout << endl;
        init_space -= 2;
    }
}

void pattern13(int n){
    int ct=1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            cout << ct << " ";
            ct++;
        }
        cout << endl;
    }
}

void pattern14(int n){
    for(int i=0; i<n; i++){
        for(char ch='A'; ch <= 'A' + i; ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern15(int n){
    for(int i=0; i<n; i++){
        for(char ch='A'; ch<= 'A' + (n-i-1); ch++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern16(int n){
    for(int i=0; i<n; i++){
        char ch = 'A'+i;
        for(int j=0; j<=i; j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void pattern17(int n){
    for(int i=0; i<n; i++){
        // spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        // letters
        char ch = 'A';
        int mid = (2*i+1) / 2;
        for(int j=0; j<2*i+1; j++){
            cout << ch;
            if(j<mid){
                ch++;
            }else{
                ch--;
            }
        }
        // spaces
        for(int j=0; j<n-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void pattern18(int n){
    char ch = 'A' + n -1;
    for(int i=0; i<n; i++){
        char tch = ch;
        for(int j=0; j<=i; j++){
            cout << tch << " ";
            tch++;
        }
        cout << endl;
        ch -= 1;
    }
}

void pattern19(int n){
    int init_space =0;
    for(int i=0; i<n; i++){
        // stars
        for(int j=0; j<n-i; j++){
            cout << "*";
        }
        // spaces
        for(int j=0; j<init_space; j++){
            cout << " ";
        }
        // stars
        for(int j=0; j<n-i; j++){
            cout << "*";
        }

        cout << endl;
        init_space+=2;
    }
}

void pattern20(int n){
    // Square 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

void pattern21(int n){
    // Number box
    for(int i=0; i<2*n -1; i++){
        for(int j=0; j<2*n-1; j++){
            int top =i;
            int left = j;
            int right = (2*n -2) - j;
            int bottom = (2*n -2) - i;

            cout << (n - min(min(top, bottom), min(left, right)));
        }
        cout << endl;
    }
}

int main()
{
    pattern21(5);
    return 0;
}