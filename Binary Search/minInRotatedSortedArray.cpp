#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinimum(vector<int> arr){
    int low = 0;
    int high = arr.size()-1;

    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[mid]){
            // left half is sorted
            ans = min(ans, arr[low]);
            low = mid+1;
        }else{
            ans = min(ans, arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    
    vector<int> arr = {7,8,2,3,4,5,6};

    int ans = findMinimum(arr);
    cout << ans;

    return 0;
}