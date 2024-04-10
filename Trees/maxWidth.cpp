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

int getMaxWidth(TreeNode *root){
    if(!root){
        return 0;
    }
    int maxWidth = 0;
    // node, idx
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        int size = q.size();
        int mini = q.front().second;
        int first;
        int last;
        for(int i=0; i<size; i++){
            int idx = q.front().second - mini;
            TreeNode *temp = q.front().first;
            q.pop();

            if(i==0) first = idx;
            if(i==size-1) last = idx;

            if(temp->left){
                q.push({temp->left, 2*idx+1});
            }
            if(temp->right){
                q.push({temp->right, 2*idx+2});
            }
        }
        maxWidth = max(maxWidth, last-first+1);
    }

    return maxWidth;
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

    
    int ans = getMaxWidth(root);
    cout << ans;

    return 0;
}