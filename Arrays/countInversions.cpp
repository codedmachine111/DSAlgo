#include <iostream>
#include <vector>
using namespace std;

int countInversionPairsBrute(vector<int> arr){
    int n = arr.size();
    int count =0;

    for(int i=0; i<n ; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }

    return count;
}

int countAndMerge(vector<int> &arr, int start, int mid, int end){

    vector<int> temp;

    int left = start;
    int right = mid+1;
    int count=0;
    while(left <= mid && right <=end){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            count += (mid - left +1);
            right++;
        }
    }

    while(left <=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= end){
        temp.push_back(arr[right]);
        right++;
    }

    for(int j=start; j<=end; j++){
        arr[j] = temp[j-start];
    }

    return count;
}

int mergeSort(vector<int> &arr, int start, int end){
    int c = 0;
    if(start == end){
        return c;
    }
    int mid = start + (end-start)/2;

    c += mergeSort(arr,start,mid);
    c += mergeSort(arr,mid+1,end);

    c += countAndMerge(arr,start,mid,end);
    return c;
}

int countInversionPairsOptim(vector<int> arr, int n){
    int ct = mergeSort(arr, 0, n-1);
    return ct;
}


int main(){
    vector<int> arr = {5, 3, 2, 4, 1};

    int ans = countInversionPairsOptim(arr, arr.size());

    cout << ans << endl;

    return 0;
}
