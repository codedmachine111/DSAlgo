#include <iostream>
using namespace std;
#include <vector>

int findAppOnce(int arr[], int n){
    int xor1=0;
    for(int i=0; i<n ; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

int findAppOnceBrute(int arr[], int n){
    vector<int> map(n,0);

    for(int i=0; i<n; i++){
        map[arr[i]] += 1;
    }

    for(int i=0; i<n; i++){
        if(map[i]==1){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {1,1,2,2,3,3,4,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int num = findAppOnceBrute(arr,size);
    cout << num;
    return 0;
}