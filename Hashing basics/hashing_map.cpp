#include<iostream>
using namespace std;
#include <map>
#include <unordered_map>

pair<int,int> findMinMax(map<int,int> &m){
    int max = 0;
    int min = INT_MAX;
    int minElem, maxElem;
    for(auto it: m){
        if(it.second > max){
            max = it.second;
            maxElem = it.first;
        }else if(it.second < min){
            min = it.second;
            minElem = it.first;
        }
    }

    return {minElem,maxElem};
}

int main(){

    int arr[] = {1,2,3,2,1,2,3,3,2,91};
    int q[] = {3,2,1,91};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    int n2 = sizeof(q)/sizeof(q[0]);

    // Precompute
    map<int,int> m;
    for(int i=0; i<n1; i++){
        m[arr[i]]++;
    }

    // Iterate
    for(auto it: m){
        cout << it.first << "-->" << it.second<< endl;
    }
    // fetch
    // for(int i=0; i<n2; i++){
    //     cout << q[i] << " : " << m[q[i]] << "\n";
    // }

    pair <int,int> minMax = findMinMax(m);

    cout << minMax.first << endl;
    cout << minMax.second << endl;
    return 0;
}