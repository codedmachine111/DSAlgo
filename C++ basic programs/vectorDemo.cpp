#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int elems, elem;
    cin >> elems;
    for(int i =0; i<elems; i++){
        cin >> elem;
        v.insert(v.end(),elem);
    }
    for(auto it : v){
        cout<< it << " ";
    }
}