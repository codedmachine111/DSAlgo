#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findLongestSABrute(int arr[], int n, int sum){
    // O(n^2)
    int s;
    int max =0;
    int count;
    for(int i=0; i<n; i++){
        s =0;
        count =0;
        for(int j=i; j<n; j++){
            s += arr[j];
            count += 1;
            if(s==sum and count>max){
                max = count;
            }
        }
    }
    return max;
}

int findLongestSABetter(vector<int> a, long long k){
    map<long long, int> preSum;
    long long s =0;
    int maxLength = 0;

    for(int i=0; i<a.size(); i++){
        s += a[i];
        if(s==k){
            maxLength = max(maxLength, i+1);
        }
        long long rem = s -k;
        if(preSum.find(rem) != preSum.end()){
            int len = i - preSum[rem];
            maxLength = max(maxLength, len);
        }
        if(preSum.find(s) == preSum.end()){
            preSum[s] = i;
        }
    }
    return maxLength;
}

int LSAOptim(int arr[], int n, int k){
    int right =0, left=0;
    int sum = arr[0];
    int maxLen = 0;
    while(right < n){

        while(left <= right && sum >k){
            sum -= arr[left];
            left++;
        }
        if(sum==k){
            maxLen = max(maxLen, right-left+1);
        }
        right+=1;
        if(right < n) sum += arr[right];
    }
    return maxLen;
}

int main(){
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 3;
    

    int longest = LSAOptim(arr,size,sum);
    cout << longest;
    return 0;
}