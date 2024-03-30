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

int height(TreeNode *root){
    if(root==NULL){
        return 0;
    }

    int lh = height(root->left);
    if(lh==-1) return -1;
    int rh = height(root->right);
    if(rh == -1) return -1;
    if(abs(lh-rh) > 1) return -1;

    return 1 + max(lh, rh);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    int ans = height(root);
    cout << ans;

    return 0;
}