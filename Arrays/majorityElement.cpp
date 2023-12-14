#include <iostream>
#include <vector>
using namespace std;

int majorityBrute(int arr[], int n){
    int x = n/2;

    vector<int> hash(n,0);

    for(int i=0; i<n; i++){
        hash[arr[i]]++;
        if(hash[arr[i]] > x){
            return arr[i];
        }
    }

    return -1;
}

int majorityMooresVotingAlgo(int arr[], int n){
    // Moores voting algo
    int x = n/2;
    int count =0;
    int el;
    for(int i=0; i<n; i++){
        if(count ==0){
            count=1;
            el = arr[i];
        }
        else if(arr[i] == el){
            count++;
        }else{
            count--;
        }
    }
    int ct=0;
    for(int i=0; i<n; i++){
        if(arr[i] == el){
            ct++;
        }
    }
    if(ct>x){
        return el;
    }
    return -1;
}

int main(){

    int arr[] = {2,2,3,3,1,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    int majority = majorityMooresVotingAlgo(arr,size);
    cout << majority;

    return 0;
}