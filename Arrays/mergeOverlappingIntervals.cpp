#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> getMergedIntervalsBrute(vector<vector<int>> arr){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j = i+1; j<n; j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }

    return ans;
}

vector<vector<int>> getMergedIntervalsOptim(vector<vector<int>> arr){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        // if empty or when first elem of current is greater than second of ans (create new arr)
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[1] = max(arr[i][1], ans.back()[1]);
        }        
    }

    return ans;
}
int main(){
    vector<vector<int>> arr{{1,3}, {2,6},{8,9}, {9,11}, {8,10}, {2,4},{15,18}, {16,17}};

    vector<vector<int>> ans = getMergedIntervalsOptim(arr);

    for(int i =0; i<ans.size(); i++){
        for(auto j: ans[i]){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}