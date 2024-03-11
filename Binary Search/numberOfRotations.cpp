#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findRotations(vector<int> arr){
    // (N- Min element's index) = number of rotations

    int low =0;
    int high = arr.size()-1;
    int idx = -1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;
        
        //if left half is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                idx = low;
            }
            low = mid+1;
        }else{
            // right half is sorted
            if(arr[mid] < ans){
                ans = arr[mid];
                idx = mid;
            }
            high = mid-1;
        }
    }
    return arr.size() - idx;
}

int main(){

    vector<int> arr = {4,5,1,2,3};
    int ans = findRotations(arr);
    cout << ans;

    return 0;
}