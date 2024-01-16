#include <iostream>

using namespace std;

class Operations{
    public:
        virtual int area(int x, int y) const {
            return 0;
        }
        virtual int area(int x, int y, int z) const {
            return 0;
        };
};

class Square: public Operations{
    public:
        int length;
        int breadth;
        
        Square(int x, int y){
            this->length = x;
            this->breadth = y;
        }

        int area(int x, int y) const{
            return x*y;
        }
};

class Cube: public Operations{
    public:
        int l,b,h;

        Cube(int x, int y, int z){
            this->l = x;
            this->b = y;
            this->h = z;
        }

        int area(int x, int y, int z) const{
            return x * y *z;
        }
};

int main(){
    Square s1(10,20);
    Cube c1(10,10,10);

    cout << s1.area(s1.length, s1.breadth) << endl;
    cout << c1.area(c1.l, c1.b, c1.h) << endl;

    return 0;
}