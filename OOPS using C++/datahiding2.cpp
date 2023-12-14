#include <iostream>
using namespace std;

class Integer{
    private:
        int i;
    public:
        void setInt(int i){
            this->i = i;
        }

        int getInt(){
            return this->i;
        }
};

int main(){
    Integer num;
    num.setInt(10);

    cout << num.getInt();
    
    return 0;
}