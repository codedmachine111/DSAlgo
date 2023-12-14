#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findMajorityBrute(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
        int ct =0;
        for(int j=i; j<n; j++){
            if(arr[j] == arr[i]){
                ct++;
            }
        }
        if (ct > n/3){
            ans.emplace_back(arr[i]);
        }
    }
    return ans;
}

vector<int> findMajorityBetter(vector<int> arr){
    int n = arr.size();
    vector<int> ans;
    map<int,int> mpp;

    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    for(auto it: mpp){
        if(it.second > n/3){
            ans.emplace_back(it.first);
        }
    }

    return ans;
}

vector<int> findMajorityOptim(vector<int> arr){

    vector<int> ans;

    int ct1=0, ct2=0;
    int el1,el2;
    for(int i=0; i<arr.size(); i++){
        if(ct1==0 && arr[i]!=el2){
            ct1=1;
            el1 = arr[i];
        }
        else if(ct2==0 && arr[i]!=el1){
            ct2=1;
            el2 = arr[i];
        }
        else if(el1 == arr[i]){
            ct1++;
        }
        else if(el2 == arr[i]){
            ct2++;
        }
        else{
            ct1--;
            ct2--;
        }
    }
    ct1=0, ct2=0;
    for(int i=0; i<arr.size(); i++){
        if(el1 == arr[i]) ct1++;
        if(el2 == arr[i]) ct2++;
    }
    if(ct1 > arr.size()/3){
        ans.emplace_back(el1);
    }
    if(ct2 > arr.size()/3){
        ans.emplace_back(el2);
    }

    return ans;
}

int main(){

    vector<int> arr{1,1,1,3,3,2,2,2};
    vector<int> ans;
    ans = findMajorityOptim(arr);
    for (auto it: ans){
        cout << it << endl;
    }

    return 0;
}