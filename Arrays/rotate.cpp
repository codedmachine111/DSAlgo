#include <iostream>
using namespace std;

void leftRotateBrute(int arr[], int n){
    int temp = arr[0];

    for(int i=1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

void leftRotateKBrute(int arr[], int n, int k){
    k = k % n;
    int temp[k];
    for(int i=0; i<k; i++){
        temp[i] = arr[i];
    }

    for(int i=k; i<n; i++){
        arr[i-k] = arr[i];
    }

    int j=0;
    for(int i=n-k; i<n; i++){
        arr[i] = temp[j];
        j++;
    }
}

void reverse(int arr[], int start, int end){
    while(start<=end){
        int temp = arr[start];
        arr[start]= arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotateKOptim(int arr[], int n, int k){
    
    reverse(arr, 0,k-1);
    reverse(arr, k, n-1);
    reverse(arr,0,n-1);
}

void moveZeros(int arr[], int n){
    // O(2N)
    int temp[n], ct=0;
    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            temp[ct]=arr[i];
            ct++;
        }
    }

    for(int i=0; i<ct; i++){
        arr[i] = temp[i];
    }

    for(int i=ct; i<n; i++){
        arr[i]=0;
    }
}

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a]= arr[b];
    arr[b] = temp;
}

void moveZerosOptim(int arr[], int n){
    // O(N)
    int j=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1; i<n; i++){
        if(arr[i]!=0){
            swap(arr,i,j);
            j++;
        }
    }
}

int linearSearch(int arr[], int target, int n){
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {1,2,3,0,0,4,0,5,0,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int idx = linearSearch(arr,4,size);

    cout << idx;
    return 0;
}