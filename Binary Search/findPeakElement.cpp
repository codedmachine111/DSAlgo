#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> arr){
    int n = arr.size();
    if(n==1) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-1] > arr[n-2]) return arr[n-1];

    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
            return arr[mid];
        }else if(arr[mid] > arr[mid-1]){
            // increasing curve - Search in right side
            low = mid+1;
        }else if(arr[mid] > arr[mid+1]){
            // decreasing curve - Search in left side
            high = mid-1;
        }else{
            // something like 4,1,5 where 1 is mid - Search either side, doesnt matter
            low = mid-1;
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {1,2,3,4,5,3,1,0};

    int ans = findPeakElement(arr);
    cout << ans;

    return 0;
}