#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int nthRootOfM(int n, int m){
    int low = 1;
    int high = m;
    while(low <= high){
        int mid= low + (high-low)/2;
        int prod = pow(mid,n);
        if(prod==m){
            return mid;
        }else if(prod > m){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int n = 4;
    int m = 81;

    int ans = nthRootOfM(n,m);
    cout << ans;

    return 0;   
}