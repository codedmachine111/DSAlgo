#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void pairDemo(){
    pair<int,int> p = {1,2};
    // cout << p.first << p.second;

    pair<int, pair<int, int>> p1 = {1,{10,100}};
    cout << p1.first << p1.second.second << p1.second.first << endl;

    pair<int, int> arr[] = {{1,2},{1,3},{1,4}};
    cout<< arr[1].second;
}

void vectorDemo(){
    vector<int> v;

    v.push_back(1);
    v.emplace_back(10);

    vector<pair<int,int>> pov;
    pov.push_back({1,2});
    pov.emplace_back(3,4);

    vector<int> filled(5,69);

    vector<int> gfilled(5);

    vector<int> copy(v);

    vector<int>:: iterator it = v.begin();
    it++;
    cout << *(it) << endl;   // * to get value inside the ADDRESS

    vector<int>:: iterator it1 = v.end();
    it1--;
    cout<< *(it1) << endl;

    // iterating vector using iterator
    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        cout<< *(it) << endl;
    }

    for(auto it : v){
        cout<< it << endl;
    }

    v.insert(v.begin(),7);
    v.insert(v.begin(),7);
    v.insert(v.begin(),7);
    for(auto it : v){
        cout<< it << " ";
    }
    cout<< endl;
    v.insert(v.begin()+1,3,100);
    for(auto it: v){
        cout<< it<<" ";
    }
}

void listDemo(){
    list<int> l1;

    l1.push_back(1);
    l1.emplace_back(10);

    l1.push_back(100);
    l1.push_front(500);

    for(auto it:l1){
        cout<< it << " ";
    }
}

void stackDemo(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<< s.top() << endl;
    cout<< s.size() << endl;

    s.pop();
    cout << s.top() << endl;
}

void queueDemo(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout<< q.front()<< endl;
    cout<< q.back()<<endl;
    q.pop();
    cout<< q.size()<<endl;
}

void setDemo(){
    set<int> set;
    set.insert(10);
    set.insert(20);
    set.insert(30);
    set.insert(40);

    auto it = set.find(30);
    cout << *(it) << endl;

    set.erase(40);
    for(auto it: set){
        cout << it << " ";
    }

}

void mapDemo(){
    // key, value
    map<int, int> map;
    std::map<std::pair<int, int>, int> map1;
    std::map<int, std::pair<int, int>> map2;

    map[1] = 2;
    map.emplace(3,10);
    map.insert(2,6);

    map1[{2,2}]=100;

}

void algoDemo(){
    int arr[10] = {1,2,3,422,5432,64,37,28,92,0};
    int len = sizeof(arr)/sizeof(arr[0]);

    sort(arr,arr+len, greater<int>());
    for(int i=0; i<len; i++){
        cout<<arr[i] << " ";
    }
}

int main(){
    algoDemo();
    return 0;
}