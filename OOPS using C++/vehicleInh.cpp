#include <iostream>
using namespace std;

class Vehicle{
    private:
        int year;
        float mileage;
        float price;
    public:
        // Vehicle(int year, float mileage, float price){
        //     this->year = year;
        //     this->mileage = mileage;
        //     this->price = price;
        // }

        void start(){
            cout << "Start" << endl;
        }

        void setInfo(int year, float mileage, float price){
            this->year = year;
            this->mileage = mileage;
            this->price = price;
        }
        void vehInfo(){
            cout << this->year << endl;
            cout << this->mileage << endl;
            cout << this->price << endl;
        }
};

class FourWheeler{
    private:
        int wheels = 4;
    public:
        void getWheels(){
            cout << wheels << endl;
        }
};

class BMW:public Vehicle, public FourWheeler{
    public:
        
        void getGPSData(){
            cout << "Get " << endl;
        }
};

class TwoWheeler:public Vehicle{
    protected:
        int wheels = 2;
    public:
        void getWheels(){
            cout << this->wheels;
        }
};

class Activa:public TwoWheeler{
    public:
        void getWheels(){
            cout << wheels << endl;
        }
};

int main(){

    // BMW car1;
    Activa act1;

    act1.setInfo(2003, 12.2, 11111.1);
    act1.vehInfo();

    return 0;
}