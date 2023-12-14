#include <iostream>
using namespace std;

void print1toN(int n){
    if(n==0){
        return;
    }
    print1toN(n-1);
    cout << n << " ";
}

int sumtoNFunc(int n){
    if(n==1){
        return 1;
    }
    return n + sumtoNFunc(n-1);
}

void printNto1(int n){
    if(n==0){
        return;
    }
    cout << n << " ";
    printNto1(n-1);
}

int sumtoNParam(int n, int sum){
    if(n==0){
        return sum;
    }
    return sumtoNParam(n-1,sum+n);
}

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n * factorial(n-1);
}

int fibonacci(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){

    // print 1 to N
    int n;
    cin >> n;
    // print1toN(n);

    // print N to 1
    // printNto1(n);

    // sum to N parameterized
    // int s = sumtoNParam(n,0);
    // cout << "Sum " << s;

    // sum to N Functional
    // int s = sumtoNFunc(n);
    // cout << "Sum " << s;

    // Factorial of N
    // int fac = factorial(n);
    // cout << "Factorial: " << fac;

    // Nth fibonacci number
    int nfib = fibonacci(n);
    cout << "Nth fibinacci : " << nfib;
    return 0;
}