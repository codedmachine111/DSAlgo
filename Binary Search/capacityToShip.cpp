#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int maxi = INT_MIN;
    int n = arr.size();
    for(int i=0; i<n; i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int sumArray(vector<int> arr){
    int sum =0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    return sum;
}

int getTotalDays(vector<int> arr, int cap){
    int days=1;
    int load =0;
    for(int i=0; i<arr.size(); i++){
        if(load+arr[i] > cap){
            // load next day
            days++; 
            load = arr[i];
        }else{
            // load same day
            load+=arr[i];
        }
    }
    return days;
}

int getMinCap(vector<int> arr, int d){
    int low = findMax(arr);
    int high = sumArray(arr);

    while(low <= high){
        int mid = low + (high-low)/2;
        int days = getTotalDays(arr, mid);
        if(days <= d){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    int ans = getMinCap(arr,days);
    cout << ans;

    return 0;
}