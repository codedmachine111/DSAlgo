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

TreeNode *previous = NULL;
void flatten1(TreeNode* root){
    if(root==NULL){
        return;
    }

    flatten1(root->right);
    flatten1(root->left);

    root->left=NULL;
    root->right = previous;
    previous = root;
}

void flatten2(TreeNode* &root){
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode *cur = st.top();
        st.pop();

        if(cur->right){
            st.push(cur->right);
        }
        if(cur->left){
            st.push(cur->left);
        }

        if(!st.empty()){
            cur->right = st.top();
        }
        cur->left = NULL;
    }
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

    flatten2(root);
    while(root!=NULL){
        cout << root->data << "->";
        root=root->right;
    }

    return 0;
}