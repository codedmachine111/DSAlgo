#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrPosNegOptim(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,0);
    int pos=0, neg=1;

    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            ans[pos] = arr[i];
            pos +=2;
        }else{
            ans[neg] = arr[i];
            neg+=2;
        }
    }

    return ans;
}

vector<int> rearrPosNegBrute(vector<int> arr){
    int  n = arr.size();
    vector<int> ans(n,0);
    int k=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > 0 && k%2==0){
            ans[k] = arr[i];
            k +=2;
        }
    }
    k=1;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < 0 && k%2!=0){
            ans[k] = arr[i];
            k +=2;
        }
    }
    return ans;
}

vector<int> rearrPosNegVar2(vector<int> arr){
    vector<int> pos;
    vector<int> neg;

    for(int i=0; i<arr.size(); i++){
        if(arr[i]>0){
            pos.emplace_back(arr[i]);
        }else{
            neg.emplace_back(arr[i]);
        }
    }
    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            arr[i*2] = pos[i];
            arr[i*2 + 1] = neg[i];
        }
        int ind = neg.size() * 2;
        for(int i=neg.size(); i<pos.size(); i++){
            arr[ind] = pos[i];
            ind++;
        }
    }else{
        for(int i=0; i<pos.size(); i++){
            arr[i*2] = pos[i];
            arr[i*2 + 1] = neg[i];
        }
        int ind = pos.size() * 2;
        for(int i=pos.size(); i<neg.size(); i++){
            arr[ind] = neg[i];
            ind++;
        }
    }
    
    return arr;
}

int main(){

    vector<int> arr{-1,2,3,4,-3,1,2,3};

    vector<int> ans = rearrPosNegVar2(arr);
    for(auto it : ans){
        cout << it << " ";
    }    

    return 0;
}