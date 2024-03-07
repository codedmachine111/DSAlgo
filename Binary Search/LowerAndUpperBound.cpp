#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getLowerBound(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int getUpperBound(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,3,7,8,9,9,9,11};
    int x = 8;

    int ans = getLowerBound(arr,x);
    cout << ans;

    return 0;
}