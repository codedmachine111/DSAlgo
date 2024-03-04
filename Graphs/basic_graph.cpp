#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    // if 1 based indexing graph ==> adj[n+1][n+1] (Adjacency Matrix)
    vector<vector<int>> adj;
    adj.resize(n+1, vector<int>(n+1));

    for(int i=0; i<m ; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    // if 1 based indexing graph ==> adj[n+1] (Adjacency List)
    vector<int> adj[n+1];

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    // if directed graph this line is not required
    }

    for(auto it: adj){
        for(int i=0; i<it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }

    return 0;
}