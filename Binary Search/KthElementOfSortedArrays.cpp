#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getKthElementBrute(vector<int> arr1, vector<int> arr2, int k){
    int left =0;
    int right =0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    int x=0;
    while(left < n1 && right <n2){
        if(arr1[left] <= arr2[right]){
            x++;
            if(x==k){
                return arr1[left];
            }
            left++;
        }else{
            x++;
            if(x==k){
                return arr2[right];
            }
            right++;
        }
    }

    while(left <n1){
        x++;
        if(x==k){
            return arr1[left];
        }
        left++;
    }

    while(right <n2){
        x++;
        if(x==k){
            return arr2[right];
        }
        right++;
    }
    return 0;
}

int getKthElementBS(vector<int> arr1, vector<int> arr2, int k){
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    if(n1>n2) return getKthElementBS(arr2,arr1,k);
    int low = max(0, k-n2);
    int high = max(k,n1);
    int n = n1 + n2;

    int left = k;

    
    while(low <= high){
        int mid1 = low + (high-low)/2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = arr1[mid1];
        if(mid2 < n2) r2 = arr2[mid2];

        if(mid1-1 >=0) l1 = arr1[mid1-1];
        if(mid2-1 >=0) l2 = arr2[mid2-1];

        if(l1<=r2 && l2 <=r1){
            return max(l1,l2);
        }else if(l1 > r2){
            high = mid1-1;
        }else{
            low = mid1 +1;
        }
    }

    return 0;
}

int main(){
    vector<int> arr1 = {2,3,6,7,9};
    vector<int> arr2 = {1,4,8,10};
    int k = 4;
    int ans = getKthElementBrute(arr1, arr2, k);
    cout << ans;

    return 0;
}