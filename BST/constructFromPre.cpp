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

TreeNode *constFromPre(vector<int> &preorder, int &i, int upperbound){
    if(i==preorder.size() || preorder[i]>upperbound) return NULL;

    TreeNode *root = new TreeNode(preorder[i]);
    i++;
    root->left = constFromPre(preorder, i, root->data);
    root->right = constFromPre(preorder, i, upperbound);
    return root;
}

int main(){

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int i=0;
    TreeNode *root = constFromPre(preorder, i, INT_MAX);
    cout << root->data;

    return 0;
}