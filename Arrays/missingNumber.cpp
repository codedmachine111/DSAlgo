#include <iostream>
#include <vector>
using namespace std;

int findMissing(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return -1;
}

int findMissingOptim(int arr[], int n) {
    vector<int> h(n + 1, 0);

    for (int i = 0; i < n; i++) {
        h[arr[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (h[i] == 0) {
            return i;
        }
    }
    return -1;
}

int findMissingOP(int arr[], int N){
    int xor1 =0, xor2=0;
    int n = N-1;
    for(int i=0; i<n;i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int n = findMissingOP(arr, 5);
    cout << n;
    return 0;
}
