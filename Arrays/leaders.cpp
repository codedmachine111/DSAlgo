#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> findLeadersBrute(vector<int> arr){
    vector<int> ans;

    for(int i=0; i<arr.size(); i++){
        int flag = 0;
        for(int j=i+1; j<=arr.size(); j++){
            if(arr[j] > arr[i]){
                flag=1;
                break;
            }
        }
        if (flag==0){
            ans.emplace_back(arr[i]);
        }
    }
    return ans;
}

vector<int> findLeadersOptim(vector<int> arr){
    vector<int> ans;

    int max = INT_MIN;

    for(int i=arr.size()-1; i>=0; i++){
        if(arr[i] > max){
            max = arr[i];
            ans.emplace_back(arr[i]);
        }
    }

    std::sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr{10,22,12,3,0,6};
    vector<int> ans;

    ans = findLeadersBrute(arr);

    for(auto it: ans){
        cout << it << endl;
    }

    return 0;
}