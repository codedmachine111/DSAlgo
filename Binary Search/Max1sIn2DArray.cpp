#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int x){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] >= x){
            ans = mid;
            high= mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int findMaxOnes(vector<vector<int>> arr){
    int maxi = INT_MIN;
    int rows = arr.size();
    int cols = arr[0].size();
    int ans;
    for(int i=0; i<rows; i++){
        int x = lowerBound(arr[i], 1); // first occ of 1
        // number of 1s
        int num = cols - x;
        if(num > maxi){
            maxi = num;
            ans = i;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{0,0,0,1,1},{0,0,1,1,1},{0,0,0,1,1}};

    int ans = findMaxOnes(arr);
    cout << ans;

    return 0;
}