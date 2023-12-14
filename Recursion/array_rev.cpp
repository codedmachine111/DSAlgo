#include <iostream>
using namespace std;

void swap(int arr[], int start, int end){
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

void reverseArray(int arr[], int start, int end){
    if(start == end){
        return;
    }
    swap(arr,start,end);
    reverseArray(arr,start+1,end-1);
}

bool isPalindrome(string str, int i){
    int n = str.size();
    if(i >= n/2){
        return true;
    }
    if(str[i] != str[n-i-1]){
        return false;
    }
    return isPalindrome(str,i+1);
}

void reverseArrayPtr(int arr[], int idx, int n){
    if(idx >= n/2){
        return;
    }   
    swap(arr[idx],arr[n-idx-1]);
    reverseArrayPtr(arr,idx+1,n);
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    reverseArrayPtr(arr,0, size);

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    string str = "goog";
    cout << "Palindrome check: " << isPalindrome(str, 0);

    return 0;
}