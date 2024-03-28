#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int val){
        data = val;
        left = right = NULL;
    }
};

void preOrder(TreeNode *root){
    if(root==NULL){
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root){
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(TreeNode *root){
    if(root==NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);

    cout << "Preorder Traversal: " << endl;
    preOrder(root);
    cout << endl;

    cout << "Inorder Traversal: " << endl;
    inOrder(root);
    cout << endl;

    cout << "Postorder Traversal: " << endl;
    postOrder(root);
    cout << endl;

    return 0;   
}