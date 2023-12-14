#include <iostream>
#include <vector>
using namespace std;

int getMaxLengthBrute(vector<int> arr){
    int length = 1;
    for(int i=0; i<arr.size(); i++){
        int num= arr[i];
        int l=1;
        int j=0;
        while(arr[j] == num +1){
            num = num + 1;
            l+=1;
            j++;
        }
        if(l>length){
            length = l;
        }
    }
    return length;
}

int main(){

    vector<int> arr{102,101,100,99,98,3,2,1,1};

    int max = getMaxLengthBrute(arr);
    cout << max << endl;

    return 0;
}