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

int getMaxPathSum(TreeNode *root, int &maxi){
    if(root==NULL){
        return 0;
    }

    int leftSum = getMaxPathSum(root->left, maxi);
    int rightSum = getMaxPathSum(root->right, maxi);

    maxi = max(maxi, root->data + leftSum + rightSum);

    return root->data + max(leftSum, rightSum);
}

int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    int maxi =0;
    int ans = getMaxPathSum(root, maxi);
    cout << maxi;

    return 0;
}