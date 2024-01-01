#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subArrWithXORkBrute(vector<int> arr, int k){
    int n = arr.size();
    int count =0;

    for(int i=0; i<n; i++){
        int xor1=0;
        for(int j=i; j<n; j++){
            xor1 = xor1 ^ arr[j];
            if(xor1 == k){
                count++;
            }
        }
    }
    return count;
}

int subArrWithXORkOptim(vector<int> a, int k){
    // x = XR ^ k
    // Hashmap for (frontXOR, x)
    int xr =0;
    map<int,int> mpp;
    mpp[xr]++;
    int count =0;
    for(int i=0; i<a.size(); i++){
        xr = xr ^ a[i];

        int x = xr ^ k;

        count += mpp[x];

        mpp[xr]++;

    }
    return count;
}


int main(){

    vector<int> arr = {4,2,2,6,4};
    int k=6;
    int ct = subArrWithXORkOptim(arr,k);
    cout << ct << endl;

    return 0;
}