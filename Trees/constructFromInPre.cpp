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

TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> inMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = build(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
    root->right = build(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int> inorder, vector<int> preorder){
    map<int, int> inMap;

    for(int i=0; i<preorder.size(); i++){
        inMap[inorder[i]] = i;
    }

    TreeNode *root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

    return root;
}

int main(){
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> preorder = {10, 20, 40, 50, 30, 60};

    TreeNode *ans = buildTree(inorder, preorder);
    cout << ans->data;
    return 0;
}