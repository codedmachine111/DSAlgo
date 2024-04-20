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

void inorder(TreeNode *root, int &ct, int k, int &ans){
    if(root==NULL){
        return;
    }
    inorder(root->left, ct, k, ans);
    ct++;
    if(ct==k){
        ans = root->data;
        return;
    }
    inorder(root->right, ct, k, ans);
}

int kthLargest(TreeNode *root){
    return 0;
}

int main(){

    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);

    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(4);

    int k =2;
    int ans =-1;
    int ct=0;
    inorder(root, ct, k, ans);
    cout << ans << endl;

    return 0;
}