#include <iostream>
using namespace std;

int maxConsecOnes(int arr[], int n){
    int max =0;
    int count =0;
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            count+=1;
            if(max < count){
                max = count;
            }
        }else{
            count =0;
        }
    }

    return max;
}

int main(){
    int arr[] = {1,1,1,0,0,1,1,0,0,0,1,1,1,1,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int max = maxConsecOnes(arr,size);
    cout << max;
    return 0;
}