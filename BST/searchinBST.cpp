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

TreeNode* searchInBST_R(TreeNode *root, int val){
    if(root==NULL || root->data==val){
        return root;
    }

    if(root->right && val > root->data){
        return searchInBST_R(root->right, val);
    }
    if(root->left && val < root->data){
        return searchInBST_R(root->left, val);
    }
    return NULL;
}

TreeNode *searchInBST(TreeNode *root, int val){
    while(root!=NULL && root->data!=val){
        root = (val>root->data) ? root->right : root->left;
    }
    return root;
}

int main(){

    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);

    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(4);

    int val = 4;
    TreeNode *ans = searchInBST(root, val);
    cout << ans->data;

    return 0;
}