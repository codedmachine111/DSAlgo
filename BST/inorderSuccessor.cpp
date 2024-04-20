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

TreeNode *lcaBst(TreeNode *root, TreeNode *p, TreeNode *q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    TreeNode *left = lcaBst(root->left, p, q);
    TreeNode *right = lcaBst(root->right, p, q);

    if(left==NULL){
        return right;
    }else if(right==NULL){
        return left;
    }else{
        return root;
    }
}

int inorderSuccessor(TreeNode *root, int val){
    if(root==NULL){
        return 0;
    }
    int successor = INT_MAX;
    TreeNode *cur = root;
    while(cur){
        if(val >= cur->data){
            cur = cur->right;
        }else if(val < cur->data){
            successor = min(successor, cur->data);
            cur = cur->left;
        }
    }
    return successor;
}

int main(){

    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);

    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(4);

    int val = 4;
    int ans = inorderSuccessor(root, val);
    cout << ans;

    return 0;
}