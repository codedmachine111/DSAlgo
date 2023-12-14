#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

vector<int> getUnion(vector<int> &arr1, vector<int> &arr2){
    set<int> unique;
    vector<int> ans;
    for(auto it : arr1){
        unique.insert(it);
    }
    for(auto it : arr2){
        unique.insert(it);
    }
    for(auto it : unique){
        ans.push_back(it);
    }
    return ans;
}

vector<int> getUnionOptim(vector<int> &arr1, vector<int> &arr2){
    vector<int> u;
    int i=0,j=0;
    
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] <= arr2[j]){
            if(u.size()==0 || arr1[i]!=u.back()){
                u.push_back(arr1[i]);
            }
            i++;
        }else{
            if(u.size()==0 || arr2[j]!=u.back()){
                u.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(j<arr2.size()){
        if(u.size()==0 || arr2[j]!=u.back()){
                u.push_back(arr2[j]);
            }
        j++;
    }

    while(i<arr1.size()){
        if(u.size()==0 || arr1[i]!=u.back()){
                u.push_back(arr1[i]);
            }
        i++;
    }

    return u;
}

vector<int> intersectionArr(vector<int> &a, vector<int> &b){
    vector<int> inter;
    vector<int> visited = {0};
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(b[j] ==a[i] && visited[j]==0){
                inter.push_back(a[i]);
                visited[j]=1;
                break;
            }
            if(b[j]>a[i]){
                break;
            }
        }
    }
    return inter;
}


int main(){

    vector<int> arr1 = {4,9,5};
    vector<int> arr2 = {9,4,9,8,4};

    vector<int> u;
    u = intersectionArr(arr1,arr2);

    for(auto it : u){
        cout << it << " ";
    }

    return 0;
}