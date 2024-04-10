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

bool isSymmetricHelper(TreeNode *left, TreeNode *right){
    if(left== NULL || right==NULL){
        return left==right;
    }
    if(left->data != right->data){
        return false;
    }
    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isSymmetric(TreeNode *root){
    return root==NULL || isSymmetricHelper(root->left, root->right);
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

    int ans = isSymmetric(root);
    cout << ans;

    return 0;
}