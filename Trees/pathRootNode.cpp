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

bool getPath(TreeNode *root, vector<int> &arr, int x){
    if(root==NULL){
        return false;
    }

    arr.push_back(root->data);
    if(root->data == x){
        return true;
    }

    if(getPath(root->left, arr, x) || getPath(root->right, arr, x)){
        return true;
    }

    arr.pop_back();
    return false;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int x = 9;
    vector<int> ans;
    getPath(root, ans, x);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}