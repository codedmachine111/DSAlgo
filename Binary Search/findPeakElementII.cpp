#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxElement(vector<vector<int>> arr, int col){
    int n = arr.size();
    int maxi = INT_MIN;
    int idx;
    for(int i=0; i<n; i++){
        if(arr[i][col] > maxi){
            maxi = arr[i][col];
            idx = i;
        }
    }
    return idx;
}

vector<int> findPeak(vector<vector<int>> arr){

    int n = arr.size();
    int m = arr[0].size();

    int low = 0;
    int high = m-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        int row = maxElement(arr, mid);
        int left = (mid-1 >=0)? arr[row][mid-1] : -1;
        int right = (mid+1 < m) ? arr[row][mid+1] : -1;

        if(arr[row][mid] > left && arr[row][mid] > right){
            return {row, mid};
        }else if(arr[row][mid] < left){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return {-1,-1};
}

int main(){
    vector<vector<int>> arr = {{1,4},{3,2}};

    vector<int> ans = findPeak(arr);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
} 