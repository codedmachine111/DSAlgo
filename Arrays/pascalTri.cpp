#include <iostream>
#include <vector>
using namespace std;

int elementAtPos(int n, int r){
    // nCr
    int res =1;
    for(int i=0; i<r; i++){
        res = (res * n)/(i+1);
        n--;
    }
    return res;
}

void printRow(int r){
    int ans =1;
    for(int i=1; i<=r; i++){
        cout << ans << " ";
        ans = (ans * (r-i))/i;
    }
}

vector<int> getRow(int r){
    vector<int> row;
    int ans =1;
    for(int i=1; i<=r; i++){
        row.emplace_back(ans);
        ans = (ans * (r-i))/i;
    }
    return row;
}

vector<vector<int>> pascalTriangleBrute(int n){
    vector<vector<int>> ans;
    vector<int> row;
    for(int i=0; i< n; i++){
        row = getRow(i+1);
        ans.emplace_back(row);
    }

    return ans;
}

int main(){
    int r=5;
    int c=3;

    int x = elementAtPos(r-1,c-1);
    cout << x << endl;

    int n =6;
    printRow(n);

    vector<vector<int>> pt = pascalTriangleBrute(n);
    for(int i=0; i<n; i++){
        for(auto it: pt[i]){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}