#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> get3SumBrute(vector<int> arr){
    int n = arr.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp{arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>> get3SumBetter(vector<int> arr){
    int n = arr.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        set<int> hashSet;
        for(int j=i+1; j<n; j++){
            int third = - (arr[i] + arr[j]);
            if(hashSet.find(third) != hashSet.end()){
                vector<int> temp{arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

vector<vector<int>> get3SumOptim(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        if(i> 0 && arr[i]==arr[i-1]) continue;

        int j=i+1;
        int k = n-1;
        
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }else if(sum > 0){
                k--;
            }else{
                ans.emplace_back(vector<int>{arr[i], arr[j], arr[k]});
                j++;
                k--;
                while(j< k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> arr{-1,0,1,2,-1,-4};
    vector<vector<int>> ans = get3SumBetter(arr);

    for(int i=0; i< ans.size(); i++){
        for(auto it : ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}