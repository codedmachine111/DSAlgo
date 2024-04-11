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

TreeNode* build(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap){
    if(postStart > postEnd || inStart > inEnd) return NULL;

    TreeNode *root = new TreeNode(postorder[postEnd]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = build(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inMap);
    root->right = build(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int> inorder, vector<int> postorder){
    if(inorder.size() != postorder.size()){
        return NULL;
    }
    map<int, int> inMap;

    for(int i=0; i<inorder.size(); i++){
        inMap[inorder[i]] = i;
    }

    TreeNode *root = build(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);

    return root;
}

int main(){
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    TreeNode *ans = buildTree(inorder, postorder);
    cout << ans->data;
    return 0;
}