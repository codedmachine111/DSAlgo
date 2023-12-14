#include <iostream>
#include <set>
using namespace std;

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int placePivot(int arr[], int low, int high){

    int pivot = arr[low];
    int i=0;
    int j=high-1;

    while(i<j){
        while(arr[i] <= pivot && i<=high-1){
            i++;
        }
        while(arr[j] > pivot && i>=low+1){
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
    if(low < high){
        int partition = placePivot(arr,low,high);

        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1, high);
    }
}

int findSecBrute(int arr[], int n){
    // O(N) + O(nlogn)

    quickSort(arr,0,n-1);

    int max = arr[n-1];
    int sec=0;
    for(int i=n-2; i>=0; i--){
        if(arr[i] < max){
            sec = arr[i];
            break;
        }
    }
    return sec;
}

int findSecBetter(int arr[], int n){
    // O(n) + O(n) = O(2n)

    int l = arr[0];
    int sl = INT_MIN;

    for(int i=1; i<n; i++){
        if(arr[i] > l){
            l = arr[i];
        }
    }

    for(int i=0; i<n; i++){
        if(arr[i] > sl && arr[i] < l){
            sl = arr[i];
        }
    }
    return sl;
}

int findSecOptim(int arr[], int n){

    // O(n)
    int l = arr[0];
    int sl = -1;

    for(int i=0; i<n; i++){
        if(arr[i] > l){
            sl = l;
            l = arr[i];
        }
        else if(arr[i]< l && arr[i]>sl){
            sl = arr[i];
        }
    }
    return sl;
}

int findSecMinOptim(int arr[], int n){
    // O(n)

    int small= arr[0];
    int ssmall = INT_MAX;
    for(int i=1; i<n; i++){
        if(arr[i]<small){
            ssmall = small;
            small = arr[i];
        }else if(arr[i] >small && arr[i]<ssmall){
            ssmall = arr[i];
        }
    }
    
    return ssmall;
}

int isSorted(int arr[], int n){
    // O(n)
    for(int i=1; i<n; i++){
        if(!(arr[i]>=arr[i-1])){
                return 0;
        }
    }
    return 1;
}

void removeDuplicatesBrute(int arr[], int n){
    // Given array is sorted
    // O(nlogn) + O(n)
    set <int> nums;

    for(int i=0; i<n; i++){
        nums.insert(arr[i]);
    }

    int i=0;
    for(auto it : nums){
        arr[i] = it;
        i++;
    }
}

int removeDuplicateOptim(int arr[], int n){
    // O(n)
    int first=0;
    int count=0;
    int second;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[first]){
            count++;
            arr[first+1] = arr[i];
            first++;
        }
    }
    return count+1;
}

int main(){
    int arr[] = {1,1,1,2,2,3,4,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int count = removeDuplicateOptim(arr,size);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n" << count;

    return 0;
}