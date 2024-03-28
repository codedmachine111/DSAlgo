#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

vector<vector<int>> bfs(TreeNode *root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main(){ 
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);

    cout << "Level order Traversal (BFS)" << endl;
    vector<vector<int>> ans = bfs(root);
    for(auto tree: ans){
        for(auto it : tree){
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}