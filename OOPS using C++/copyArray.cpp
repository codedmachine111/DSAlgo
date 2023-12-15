#include <iostream>
using namespace std;

class IntArray{
    private:
        int *arr;
        int size;
    public:
        IntArray(){
            this->arr = NULL;
            this->arr = 0;
        }
        IntArray(int size){
            this->size = size;
            if(this->size==0){
                this->arr = NULL;
            }else{
                for(int i=0; i<this->size; i++){
                    arr[i] = i;
                }
            }
        }

        IntArray(IntArray &arr){
            this->size = arr.size;
            this->arr = arr.arr;
        }

        void displayArray(){
            if(this->size!=0){
                for(int i=0; i<this->size; i++){
                cout << this->arr[i] << " ";
            }
                cout << endl;
            }else{
                cout << "Empty array" << endl;
            }
        }
};


int main(){
    IntArray arr1(5);
    arr1.displayArray();

    IntArray arr2 = arr1;
    arr2.displayArray();

    return 0;
}