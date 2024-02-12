#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxProductSubarrayBrute(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int prod=1;
        for(int j=i; j<n; j++){
            prod *= arr[j];
            maxi = max(maxi,prod);
        }
    }

    return maxi;
}

int maxProductSubarrayOptim(vector<int> arr){
    int n = arr.size();
    int maxi=INT_MIN;
    int prefix=1;
    int suffix=1;

    for(int i=0; i<n; i++){
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;

        prefix *= arr[i];
        suffix *= arr[n-i-1];

        maxi = max(maxi, max(prefix, suffix));
    }

    return maxi;
}

int main(){
    vector<int> arr = {-2,3,-4,0};

    int maxProd = maxProductSubarrayOptim(arr);
    cout << maxProd;

    return 0;
}