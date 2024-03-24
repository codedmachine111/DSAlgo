#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool search2D(vector<vector<int>> arr, int target){
    int n = arr.size(); // number of rows
    int m = arr[0].size(); // number of cols
    bool isFound = false;

    int low =0;
    int high = n*m -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        int x_coord = mid / m;
        int y_coord = mid % m;

        if(arr[x_coord][y_coord] > target){
            high = mid-1;
        }else if(arr[x_coord][y_coord] < target){
            low = mid + 1;
        }else{
            isFound = true;
            break;
        }
    }

    return isFound;
}

int main(){
    vector<vector<int>> arr = {{3,4,7,9},{11,12,13,17},{22,24,28,29}};
    int target = 27;

    bool ans = search2D(arr, target);
    cout << ans;

    return 0;
}