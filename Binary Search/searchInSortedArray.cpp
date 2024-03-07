#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool searchSorted(vector<int> arr, int target){
    bool isFound = false;
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid]==target){
            return true;
        }
        // check if left half is sorted
        if(arr[low] > arr[mid]){
            if(arr[low] <= target && target <= arr[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }

    return false;
}

int main(){
    vector<int> arr = {7,8,9,1,2,3,4,5};

    int target = 3;

    if(searchSorted(arr,target)){
        cout << "Found!";
    }else{
        cout << "Not found!";
    }

    return 0;
}