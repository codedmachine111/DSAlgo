#include <iostream>
using namespace std;
#include <map>

int main(){
    int arr[] = {1,2,3,4,13,2,1,2,1,12,11};
    int n = sizeof(arr)/ sizeof(arr[0]);

    // Precompute for Hash array
    int hash[13]  = {0}; // Assuming 13 can be the max value
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int nums[]= {1,2,12,11};
    int n1 = sizeof(nums)/ sizeof(nums[0]);
    for(int i =0; i<n1 ; i++){
        cout << nums[i] << " : " << hash[nums[i]] << endl;
    }
    return 0;
}