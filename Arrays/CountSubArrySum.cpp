#include <iostream>
#include <vector>
#include <map>
using namespace std;

int countSubArrSumBrute(vector<int> arr, int k){
    int n = arr.size();
    vector<int> ans;
    int count =0;

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum = sum + arr[j];
            if(sum==k){
                count++;
                break;
            }
        }
    }

    return count;
}

int countSubArrSumOptim(vector<int> arr, int k){
    map<int,int> mpp;
    mpp[0]=1;
    int preSum=0;
    int count=0;
    for(int i=0; i<arr.size(); i++){
        preSum += arr[i];

        int rem = preSum - k;
        count += mpp[rem];
        mpp[preSum]++;
    }
    return count;
}

int main(){

    vector<int> arr{1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    int count;
    count = countSubArrSumOptim(arr,k);

    cout << count << endl;

    return 0;
}