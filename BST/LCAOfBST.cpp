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

TreeNode *lcaBst(TreeNode *root, TreeNode *p, TreeNode *q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    TreeNode *left = lcaBst(root->left, p, q);
    TreeNode *right = lcaBst(root->right, p, q);

    if(left==NULL){
        return right;
    }else if(right==NULL){
        return left;
    }else{
        return root;
    }
}

TreeNode *lcaBstOptim(TreeNode *root, TreeNode *p, TreeNode *q){
    if(root==NULL){
        return root;
    }
    if(root->data > p->data && root->data > q->data){
        root = lcaBstOptim(root->left, p, q);
    }else if(root->data < p->data && root->data < q->data){
        root = lcaBstOptim(root->right, p, q);
    }
    
    return root;
}

int main(){

    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);

    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(4);

    TreeNode *ans = lcaBstOptim(root, root->right->right, root->right->left);
    cout << ans->data;

    return 0;
}