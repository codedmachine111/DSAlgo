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

void preOrder(TreeNode *root){
    if(root==NULL){
        return;
    }

    stack<TreeNode *> st;
    st.push(root);

    while(!st.empty()){
        TreeNode *temp = st.top();
        st.pop();

        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
        cout << temp->data << " ";
    }
}

void inOrder(TreeNode *root){
    if(root == NULL){
        return;
    }

    stack<TreeNode *> st;
    TreeNode *node = root;

    while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }else{
            if(st.empty()==true) break;
            node = st.top();
            st.pop();
            cout << node->data << " ";
            node = node->right;
        }
    }
}

void postOrder2Stacks(TreeNode *root){
    if(root==NULL){
        return;
    }

    stack<TreeNode *> st1;
    stack<TreeNode *> st2;

    st1.push(root);
    while(!st1.empty()){
        TreeNode *temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);   
    }

    while(!st2.empty()){
        TreeNode *node = st2.top();
        cout << node->data << " ";
        st2.pop();
    }
}

void postOrder(TreeNode *root){
    if(root==NULL){
        return;
    }

    stack<TreeNode *> st;
    TreeNode *cur = root;

    while(cur!= NULL || !st.empty()){
        if(cur != NULL){
            st.push(cur);
            cur = cur->left;
        }else{
            TreeNode *temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                cout << temp->data << " ";

                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";  
                }
            }else{
                cur = temp;
            }
        }
    }
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

    cout << "Preorder : " << endl;
    preOrder(root);
    cout << endl;

    cout << "Inorder : " << endl;
    inOrder(root);
    cout << endl;

    cout << "postOrder2Stacks : " << endl;
    postOrder(root);
    cout << endl;

    return 0;
}