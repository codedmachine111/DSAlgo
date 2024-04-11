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

void changeTree(TreeNode *root){
    if(root==NULL){
        return;
    }

    int child=0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child < root->data){
        if(root->left) root->left->data  = root->data;
        if(root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int sum=0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;

    if(root->left || root->right) root->data = sum;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);

    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    changeTree(root);
    cout << root->data;

    return 0;
}