#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

bool isPossible(vector<int> arr, int dist, int cows){
    int placedCows = 1;
    int coords = arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i]-coords >= dist){
            placedCows++;
            coords = arr[i];
        }
        if(placedCows >= cows){
            return true;
        }
    }
    return false;
}

int getMaxDistance(vector<int> arr, int cows){
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = findMax(arr);
    while(low <= high){
        int mid = low + (high-low)/2;
        if(isPossible(arr, mid, cows)){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return high;
}

int main(){
    vector<int> arr = {0,3,4,7,9,10};
    int cows = 4;
    int ans = getMaxDistance(arr,cows);
    cout << ans;

    return 0;
}