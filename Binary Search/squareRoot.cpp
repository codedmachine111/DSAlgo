#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n){
    int low = 1;
    int high = n;
    while(low <= high){
        int mid = low + (high-low)/2;
        int sq = mid * mid;
        if(sq == n){
            return mid;
        }else if(sq < n){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return high;    // will give floor value (Closest sqrt number)
}

int main(){
    int n = 28;

    int ans = squareRoot(n);
    cout << ans;

    return 0;
}