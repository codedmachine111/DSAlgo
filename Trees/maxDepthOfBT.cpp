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

int getMaxDepth(TreeNode *root){
    if(root==NULL){
        return 0;
    }

    return 1 + max(getMaxDepth(root->left), getMaxDepth(root->right));
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

    int ans = getMaxDepth(root);
    cout << ans;

    return 0;
}