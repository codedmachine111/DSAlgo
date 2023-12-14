#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> get4SumBrute(vector<int> arr, int target){
    int n = arr.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i=1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    if((arr[i] + arr[j] + arr[k] + arr[l])==target){
                        vector<int> temp{arr[i] , arr[j] , arr[k] , arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> get4SumBetter(vector<int> arr, int target){
    int n = arr.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int> hashSet;
            for(int k=j+1; k<n; k++){
                int fourth = target - (arr[i] + arr[j] + arr[k]);
                if(hashSet.find(fourth) != hashSet.end()){
                    vector<int> temp{arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> get4SumOptim(vector<int> arr, int target){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    set<vector<int>> st;

    for(int i=0; i<n; i++){
        if (i>0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if (j!=i+1 && arr[j] == arr[j-1]) continue;
            
            int k = j+1;
            int l = n-1;

            while(k<l){
                long long  sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum < target){
                    k++;
                }else if(sum > target){
                    l--;
                }else{
                    vector<int> temp{arr[i], arr[j], arr[k], arr[l]};
                    ans.emplace_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while(k<l && arr[l]== arr[l+1]) l--;
                }
            }
        }
    }
    
    return ans;
}

int main(){

    vector<int> arr{1,0,-1,0,-2,2};
    int target =0;

    vector<vector<int>> ans = get4SumOptim(arr,target);

    for(int i=0; i<ans.size(); i++){
        for(auto it: ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}