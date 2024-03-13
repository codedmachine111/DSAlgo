#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxEL(vector<int> arr){
    int maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}

int getTotalHours(vector<int> &arr, int x){
    int total=0;
    for(int i=0; i<arr.size(); i++){
        total += ceil((double)arr[i]/x);
    }
    return total;
}

int minK(vector<int> piles, int h){
    int low = 1;
    int high = maxEL(piles);
    while(low <= high){
        int mid = low + (high-low)/2;
        int hours = getTotalHours(piles,mid);
        if(hours <= h){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h =8;

    int ans = minK(piles,h);
    cout << ans;

    return 0;
}