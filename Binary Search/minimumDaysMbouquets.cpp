#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

int findMin(vector<int> arr){
    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        mini=min(mini,arr[i]);
    }
    return mini;
}

int possible(vector<int> arr, int mid, int k, int m){
    int ct=0;
    int nob=0;
    for(int i=0; i<arr.size(); i++){
        if(mid >= arr[i]){
            ct++;
        }else{
            nob += ct/k;
            ct=0;
        }
    }
    nob += ct/k;
    return (nob>=m);
}

int getMinDays(vector<int> arr, int m, int k){
    int low = findMin(arr);
    int high = findMax(arr);

    while(low<=high){
        int mid = low + (high-low)/2;
        int total = possible(arr,mid, k, m);
        if(total == 1){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return low;
}

int main(){
    vector<int> bloomDay = {7,7,7,7,13,11,12,7};
    int m = 2;
    int k = 3;

    int minDays = getMinDays(bloomDay, m, k);
    cout << minDays;

    return 0;
}