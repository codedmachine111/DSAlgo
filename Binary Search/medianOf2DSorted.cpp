#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

int howManySE(vector<vector<int>> arr, int x){
    int ct =0;
    for(int i=0; i<arr.size(); i++){
        ct += getUpperBound(arr[i], x);
    }
    return ct;
}



int findMedian(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();
    int req = (n*m) /2;

    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0; i<n; i++){
        low = min(low, arr[i][0]);
        high = max(high, arr[i][m-1]);
    }

    while(low <= high){
        int mid = low + (high-low)/2;

        int smallerEq = howManySE(arr, mid);
        if(smallerEq <= req){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}

int main(){

    vector<vector<int>> arr = {{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};
    
    int ans = findMedian(arr);
    cout << ans;

    return 0;
}