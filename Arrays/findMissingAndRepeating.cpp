#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> findMissRepeatBrute(vector<int> arr){
    int n = arr.size();
    int miss, rep;
    vector<int> ans;
    vector<int> h(n+1, 0);

    for(int i=0; i<n; i++){
        h[arr[i]]++;
    }

    for(int i =1; i<=n; i++){
        if(h[i]==0){
            miss = i;
        }
        if(h[i]==2){
            rep = i;
        }
    }
    ans.push_back(rep);
    ans.push_back(miss);

    return ans;
}

int main(){

    vector<int> arr = {10, 11, 1 ,12, 3, 4, 13, 8, 2, 6, 7, 9, 5, 3 };

    vector<int> ans = findMissRepeatBrute(arr);

    for(auto it : ans){
        cout << it << " ";
    }

    return 0;
}