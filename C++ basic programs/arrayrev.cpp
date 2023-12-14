#include <iostream>
using namespace std;

void swap(int arr[], int start, int end){
    int temp = arr[start];
    arr[start]=arr[end];
    arr[end] = temp;
}

int main(){

    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int start = 0;
    int end = size-1;

    for(int i=0; i<size/2; i++){
        swap(arr,start,end);
        start++;
        end--;
    }

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}