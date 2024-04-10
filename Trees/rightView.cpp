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

vector<int> getRightView(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);
    vector<int> ans;

    while(!q.empty()){
        int size = q.size();
        int rightmost = q.back()->data;
        ans.push_back(rightmost);

        for(int i=0; i<size; i++){
            TreeNode *temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    return ans;
}

vector<int> getLeftView(TreeNode *root){
    queue<TreeNode *> q;
    q.push(root);
    vector<int> ans;

    while(!q.empty()){
        int size = q.size();
        int leftmost = q.front()->data;
        ans.push_back(leftmost);

        for(int i=0; i<size; i++){
            TreeNode *temp = q.front();
            q.pop();

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
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

    vector<int> ans = getLeftView(root);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}