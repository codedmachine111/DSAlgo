#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lastOccurrance(vector<int> arr, int target){
    int last = -1;
    int n = arr.size();
    int low =0;
    int high = n-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            last = mid;
            low = mid +1;
        }else if(arr[mid] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return last;
}

int firstOccurrance(vector<int> arr, int target){
    int low = 0;
    int n = arr.size();
    int high = n-1;
    int first =-1;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid-1;
        }else if(arr[mid] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return first;
}

int countOccurrance(vector<int> arr, int target){
    int first = firstOccurrance(arr, target);
    if(first==-1){
        return 0;
    }
    int last = lastOccurrance(arr, target);


    return last-first +1;
}

int main(){
    vector<int> arr = {1,2,2,2,2,2,4,4,5,7,99};

    int target = 2;

    int count = countOccurrance(arr,target);
    cout << count;

    return 0;
}   