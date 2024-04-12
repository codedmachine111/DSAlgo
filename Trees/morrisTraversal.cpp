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

vector<int> morrisInorder(TreeNode *root){
    vector<int> ans;
    TreeNode *cur = root;

    while(cur != NULL){
        if(cur->left==NULL){
            ans.push_back(cur->data);
            cur = cur->right;
        }else{
            TreeNode *prev = cur->left;
            while(prev->right && prev->right!=cur){
                prev = prev->right;
            }

            if(prev->right==NULL){
                prev->right = cur;
                cur=cur->left;
            }else{
                ans.push_back(cur->data);
                prev->right=NULL;
                cur= cur->right;
            }
        }

    }

    return ans;
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

    vector<int> inorder = morrisInorder(root);
    for(auto it: inorder){
        cout << it << endl;
    }

    return 0;
}