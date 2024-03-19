#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int findSum(vector<int> arr){
    int sum =0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    return sum;
}

int getTotalStudents(vector<int> arr, int pages, int students){
    int stu =1;
    int studentPages =0;
    for(int i=0; i<arr.size(); i++){
        if(studentPages+arr[i] <= pages){
            studentPages += arr[i];
        }else{
            stu++;
            studentPages = arr[i];
        }
    }
    return stu;
}

int getMinofMaxBooks(vector<int> arr, int students){
    int low = findMax(arr);
    int high = findSum(arr);
    while(low <= high){
        int mid = low + (high-low)/2;
        int totalStudentsPossible = getTotalStudents(arr, mid, students);
        if(totalStudentsPossible <= students){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {25, 46, 28, 49, 24};
    int students = 4;

    int ans = getMinofMaxBooks(arr,students);
    cout << ans;

    return 0;
}