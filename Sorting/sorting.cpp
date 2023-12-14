#include <iostream>
using namespace std;



void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
} 

void selectionSort(int arr[], int n){
    // Algorithm:
    // Get the minimum and then swap
    // WC : O(n2)
    for(int i=0; i<=n-2; i++){
        int minIdx = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr,i,minIdx);
    }
}

void bubbleSort(int arr[], int n){
    // Algorithm
    // Adjacent swapping. If right is smaller than left, swap
    // WC : O(n2)
    // BC : O(n)
    int isSorted;
    for(int i=0; i<n-1; i++){
        isSorted = 1;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                isSorted=0;
                swap(arr,i,j);
            }
        }
        if(isSorted){
            break;
        }
    }
}

void insertionSort(int arr[], int n){
    // Swap with left till you can
    // WC : O(n2)
    // BC : O(n)
    for(int i=0; i<n ; i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr,j,j-1);
            j--;
        }
    }
}

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

int placePivot(int arr[], int low, int high){
    int pivot = arr[low];
    int i=low, j=high;

    while(i<j){
        while(arr[i] <= pivot && i<=high-1){
            i++;
        }
        while(arr[j] > pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr,i,j);
        }
    }
    swap(arr,low,j);
    return j;
}

void quickSort(int arr[], int low, int high){

    // O(nlogn)
    if(low < high){
        int partition = placePivot(arr,low,high);

        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1, high);
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

int main(){

    int arr[] = {4,6,2,5,7,9,1,3,3,3,3,3,3,3,3,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,size-1);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}