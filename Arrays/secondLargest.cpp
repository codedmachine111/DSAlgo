#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int largestBrute(vector<int> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    return arr[n-1];
}

int largestOptim(vector<int> arr){
    int n = arr.size();
    int elem = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > elem){
            elem = arr[i];
        }
    }
    return elem;
}

int seclargestOptim(vector<int> arr){
    int n = arr.size();
    int largest = arr[0];
    int second = -1;
    for(int i=0; i<n ; i++){
        if(arr[i] > largest){
            second = largest;
            largest = arr[i];
        }
    }
    
    return second;
}

int main() {
    // Write C++ code here
    vector<int> arr = {1,2,4,42,1,33,222};

    int seclargest = seclargestOptim(arr);
    cout << seclargest;
    
    return 0;
}