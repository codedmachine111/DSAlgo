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

int getDiameter(TreeNode *root, int &d){
    if(root==NULL){
        return 0;
    }

    int lh = getDiameter(root->left, d);
    int rh = getDiameter(root->right, d);

    d = max(d, lh+rh);

    return 1 + max(lh,rh);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    int d =0;
    getDiameter(root, d);
    cout << d;

    return 0;
}