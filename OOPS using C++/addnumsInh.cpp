#include <iostream>
using namespace std;

class Nums{
    protected:
        int x, y;
    public:
        Nums(int x, int y){
            this->x = x;
            this->y = y;
        }
};

class Operation: public Nums{
    public:
        Operation(int x,int y): Nums(x,y){

        }

        int addNums(){
            return x+y;
        }
};

int main(){
    int x,y;
    cin >> x;
    cin >> y;
    Operation opr(x,y);

    int sum = opr.addNums();
    cout << sum << endl;

    return 0;
}