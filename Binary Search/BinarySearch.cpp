#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int BinarySearchRecursive(vector<int> arr, int low, int high, int target){
    if(low > high){
        return -1;
    }

    int mid = low + (high-low)/2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] < target){
        low = mid+1;
    }else{
        high = mid-1;
    }

    return BinarySearchRecursive(arr,low,high,target);
}

int BinarySearchIterative(vector<int> arr, int target){
    int low =0;
    int high = arr.size()-1;
    while(low <= high){
        int mid  = low + (high-low)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid] < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2,1,3,4,5,3,31,2,3,7,1};
    sort(arr.begin(), arr.end());

    int target = 7;
    int idx = BinarySearchRecursive(arr, 0, arr.size()-1, target);

    if(idx != -1){
        cout << "Target found!";
    }else{
        cout << "Target not found!";
    }

    return 0;
}
