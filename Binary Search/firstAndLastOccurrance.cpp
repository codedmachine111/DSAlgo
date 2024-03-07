#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getLowerBound(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

int getUpperBound(vector<int> arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n;

    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

vector<int> getFisrtandLastOcc(vector<int> arr, int x){
    vector<int> ans;
    int n = arr.size();

    int lb = getLowerBound(arr, x);
    int ub = getUpperBound(arr, x);

    if(lb ==n || arr[lb] != x){
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }else{
        ans.push_back(lb);
        ans.push_back(ub-1);
    }
    
    return ans;
}

int main(){
    vector<int> arr = {2,4,6,8,8,8,11,13};

    int x = 12;

    vector<int> ans = getFisrtandLastOcc(arr,x);
    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}