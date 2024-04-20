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

int ceilInBST(TreeNode *root, int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            break;
        }

        if(key < root->data){
            ceil = root->data;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return ceil;
}

int floorInBST(TreeNode *root, int key){
    // find <= key
    int ans = -1;
    while(root){
        if(root->data > key){
            // Go left
            root = root->left;
        }else if(root->data == key){
            return root->data;
        }else if(root->data < key){
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}

int main(){

    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);

    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(4);

    int key = 9;
    int ans = floorInBST(root, key);
    cout << ans;

    return 0;
}