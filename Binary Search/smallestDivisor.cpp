#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getSum(vector<int> arr, int mid){
    int sum =0;
    for(int i=0; i<arr.size(); i++){
        sum += ceil((double)arr[i]/(double)mid);
    }
    return sum;
}

int main(){
    vector<int> arr = {1,2,5,9};
    int t = 6;

    int low = 1;
    int high = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        high = max(high, arr[i]);
    }

    while(low <= high){
        int mid = low + (high-low)/2;
        int sum = getSum(arr,mid);
        if(sum <= t){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    cout << low;
    return 0;
}