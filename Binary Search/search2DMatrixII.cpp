#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> search2D(vector<vector<int>> arr, int target){
    int n = arr.size();
    int m = arr[0].size();

    // stand at (row, col) right most corner
    int row = 0;
    int col = m-1;
    while(row <n && col >=0){
        if(arr[row][col] == target){
            return {row,col};
        }else if(arr[row][col] > target){
            col--;
        }else{
            row++;
        }
    }

    return {-1,-1};
}

int main(){
    vector<vector<int>> arr = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 14;

    vector<int> ans = search2D(arr, target);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}