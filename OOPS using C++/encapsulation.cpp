#include <iostream>
using namespace std;

class Geo{
    private:
        int length, breadth;
        float area, perimeter;
    public:
        // Mutators
        void setLength(int l){
            length = l;
        }
        void setBreadth(int b){
            breadth = b;
        }

        // Accessors
        int getArea(){
            return length * breadth;
        }
        int getPerim(){
            return 2*(length + breadth);
        }
};

int main(){
    Geo rect;
    rect.setBreadth(10);
    rect.setLength(5);

    int area = rect.getArea();
    int perim = rect.getPerim();

    cout << "Area: " << area << " " << "Perimeter: " << perim << endl;

    return 0;
}