#include <iostream>

using namespace std;

int longestSASBrute(int arr[], int n, int sum) {
    int ct = 0; // Initialize ct to 0
    int maxi = INT_MIN;
    int s;
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = i; j < n; j++) {
            s += arr[j];
            ct++;
            if (s == sum) {
                maxi = max(maxi, j-i+1);
            }
        }
    }
    return maxi;
}


int kadaneAlgo(int arr[], int n){
    // Kanade's algo
    int max = INT_MIN;
    int sum =0;
    for(int i=0; i<n; i++){
         sum += arr[i];
        if(sum > max){
            max = sum;
        }

        if(sum <0){
            sum =0;
        }
    }
    return max;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int len = kadaneAlgo(arr, size);
    cout << len;

    return 0;
}
