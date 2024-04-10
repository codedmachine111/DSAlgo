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

TreeNode* lca(TreeNode *root, TreeNode *p,TreeNode *q){
    if(root==NULL || root==p || root==q){
        return root;
    }

    TreeNode *left = lca(root->left, p, q);
    TreeNode *right = lca(root->right, p, q);

    if(left==NULL){
        return right;
    }else if(right==NULL){
        return left;
    }else{
        return root;
    }
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

    
    TreeNode *ans = lca(root, root->left, root->right);
    cout << ans->data;

    return 0;
}