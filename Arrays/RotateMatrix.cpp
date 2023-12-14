#include <iostream>
using namespace std;

void markRows(int arr[][4], int i){
    for(int j=0; j<4; j++){
        if(arr[i][j] !=0){
            arr[i][j] = -1;
        }
    }
}

void markCols(int arr[][4], int j){
    for(int i=0; i<4; i++){
        if(arr[i][j] !=0){
            arr[i][j] = -1;
        }
    }
}

int main(){
    int r=4;
    int c=4;
    int arr[r][c] = {{1,2,3,4},{5,6,7,8},{0,0,0,0},{1,1,1,1}};
    int rotated[r][c];
    int trans[r][c];

    // Rotate matrix by 90deg
    for(int j=0; j<c; j++){
        for(int i=0; i<r; i++){
            rotated[i][c-j-1] = arr[j][i];
        }
    } 

    // Transpose matrix
    for(int j=0; j<c; j++){
        for(int i=0; i<r; i++){
            trans[i][j] = arr[j][i];
        }
    }    

    // Print the matrix
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }   
    cout << "\n";

    // Print the matrix
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}