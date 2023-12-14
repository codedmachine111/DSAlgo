#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> findIndicesBrute(int arr[], int n, int sum){
    vector<pair<int,int>> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] + arr[i] == sum){
                ans.emplace_back(i,j);
            }
        }
    }
    return ans;
}

vector<pair<int,int>> findIndicesBetter(int arr[], int n, int sum){
    map<int,int> store;
    vector<pair<int,int>> ans;
    for(int i=0; i<n; i++){
        int a = arr[i];
        int rem = sum - a;
        if(store.find(rem) != store.end()){
            ans.emplace_back(i,store[rem]);
            return ans;
        }
        store[a] = i;
    }
    return ans;
}

vector<pair<int,int>> findIndicesOptim(int arr[], int n, int sum){

    vector<pair<int,int>> ans;
    sort(arr, arr+n);

    int left=0, right=n-1;

    for(int i=0; i<n; i++){
        if(arr[left]+arr[right] < sum){
            left++;
        }
        else if(arr[left]+arr[right] > sum){
            right--;
        }else{
            ans.emplace_back(left,right);
            return ans;
        }
    }
    return ans;
}


int main(){
    int arr[] = {2,5,10,7,120};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 17;
    
    vector<pair<int,int>> ans;
    ans = findIndicesOptim(arr, size, sum);

    for(auto it : ans){
        cout << it.first << "," << it.second;
    }
    return 0;
}