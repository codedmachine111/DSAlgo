#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int temp[high];
    int left = low;
    int right = mid+1;
    int i=0;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp[i] = arr[left];
            i++;
            left++;
        }else{
            temp[i] = arr[right];
            i++;
            right++;
        }
    }

    while(left <= mid){
        temp[i] = arr[left];
        i++;
        left++;
    }

    while(right <= high){
        temp[i] = arr[right];
        i++;
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
} 


void mergeSort(int arr[], int low,int high){

    // Divide and merge
    // WC : O(nlogn)
    if(low == high){
        return;
    }
    int mid = low + (high-low) /2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,mid,high);
}

void sort012Better(int arr[], int n){
    int ct0=0,ct1=0,ct2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0) ct0++;
        else if(arr[i]==1) ct1++;
        else ct2++;
    }
    for(int i=0; i<ct0; i++){
        arr[i] = 0;
    }
    for(int i=ct0; i<ct0+ct1; i++){
        arr[i] = 1;
    }
    for(int i=ct0+ct1; i<ct0+ct1+ct2; i++){
        arr[i] = 2;
    }
}

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sort012DutchFlag(int arr[], int n){
    // Dutch National Flag algo
    int low =0;
    int high = n-1;
    int mid = 0;

    for(int i=0; i<n; i++){
        if(arr[mid]==0){
            swap(arr,mid,low);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr,mid,high);
            high--;
        }
    }
}

int main(){

    int arr[] = {2,2,2,2,0,0,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);

    // mergeSort(arr,0,size-1);
    sort012DutchFlag(arr,size);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}