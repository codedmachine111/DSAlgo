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

bool isLeaf(TreeNode *root){
    return !root->left && !root->right;
}

void addLeft(TreeNode *root, vector<int> &ans){
    TreeNode *cur = root->left;
    while(cur){
        if(!isLeaf(cur)) ans.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addLeaves(TreeNode *root, vector<int> &ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }

    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}

void addRightReverse(TreeNode *root, vector<int> &ans){
    TreeNode *cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);

        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i=temp.size()-1; i>=0; i--){
        ans.push_back(temp[i]);
    }
}

void getBoundaryTraversal(TreeNode *root, vector<int> &ans){
    addLeft(root, ans);
    addLeaves(root, ans);
    addRightReverse(root, ans);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    vector<int> ans;
    ans.push_back(root->data);
    getBoundaryTraversal(root, ans);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}