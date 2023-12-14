#include <iostream>
using namespace std;

class Numbers{
    public:
        int add(int a, int b){
            return a+b;
        }
    public:
        int subtract(int a, int b){
            return a-b;
        }
};

int addNums(int a, int b){
    return a+b;
}

int main(){
    int a =10, b= 15;

    int res = addNums(a,b);
    cout << res << endl;

    Numbers num;
    int res2 = num.subtract(a,b);
    cout << res2 << endl;
    return 0;
}