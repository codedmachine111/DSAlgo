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

bool isValid(TreeNode *root, long long min, long long max){
    if(root==NULL) return true;
    if(root->data >= max || root->data <= min) return false;
    return isValid(root->left, min, root->data) && isValid(root->right, root->data, max);
}

int main(){

    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);

    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(4);

    bool ans= isValid(root, LONG_MIN, LONG_MAX);
    cout << ans;

    return 0;
}