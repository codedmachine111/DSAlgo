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

    int arr[4][4] = {{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(arr[i][j]==0){
                markRows(arr,i);
                markCols(arr,i);
            }
        }
    }   

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}