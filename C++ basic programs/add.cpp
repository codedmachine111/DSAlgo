#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int add(int a, int b){
    return a+b;
}

int max(int a, int b){
    return (a>b) ? a : b;
}

bool checkArmstrong(int n){
	//Write your code here
	int temp=n,digit,sum=0;
	while(n>0){
		digit = n%10;
		sum += pow(digit,3);
		n= n/10;
	}
    cout << sum;
	return (temp==sum);
}

vector<int> printDivisors(int n) {
    // Write your code here
    vector<int> v;
    int count=0;
    for(int i=1; i<=n;i++){
        if(n%i==0){ 
            v.emplace_back(i);
        }
    }
    return v;
}

int min(int a, int b){
	return (a<b) ? a : b;
}

int gcd(int a,int b)
{
	//Write your code here
	int m = min(a,b);
	int gcd;
	for(int i=0; i<m; i++){
		if(a%i==0 && b%i==0){
			gcd = i;
            break;
		}
	}
	return gcd;
}

int main(){
    // cout<< "Enter the numbers: \n";
    // float a,b;
    // cin >> a >> b;
    // float sum = add(a,b);
    // cout << sum << endl;

    // int m = max(10,15);
    // cout << m;
    int g = gcd(10,15);
    cout << g;

    return 0;
}