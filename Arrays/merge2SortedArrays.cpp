#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void mergeSortedBrute(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> ans;

    int left=0, right =0;

    while(left<n1 && right < n2){
        if(arr1[left] <= arr2[right]){
            ans.push_back(arr1[left]);
            left++;
        }else{
            ans.push_back(arr2[right]);
            right++;
        }
    }

    while(left < n1){
        ans.push_back(arr1[left]);
        left++;
    }

    while(right < n2){
        ans.push_back(arr2[right]);
        right++;
    }

    for(int i=0; i<ans.size(); i++){
        if(i < n1) arr1[i] = ans[i];
        else arr2[i-n1] = ans[i];
    }
}


void mergeSortedOptim(vector<int> &arr1, vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int left = n1-1;    // last of first array
    int right = 0;      // first of second array

    while(arr1[left] > arr2[right]){
        swap(arr1[left], arr2[right]);
        left--;
        right++;
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main(){
    vector<int> arr1{1,3,5,7};
    vector<int> arr2{0,2,6,8,9};

    mergeSortedOptim(arr1, arr2);
    for(auto it: arr1){
        cout << it << " ";
    }
    cout << endl;
    for(auto it: arr2){
        cout << it << " ";
    }

    return 0;
}