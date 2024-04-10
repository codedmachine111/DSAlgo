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

vector<vector<int>> zigzag(TreeNode *root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool isLtoR = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for(int i=0; i<size; i++){
            TreeNode *temp = q.front();
            q.pop();

            int idx = (isLtoR) ? i: size-i-1;
            level[idx] = temp->data;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        ans.push_back(level);
        isLtoR = !isLtoR;
    }

    return ans;
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

    vector<vector<int>> ans = zigzag(root);
    for(int i=0; i<ans.size(); i++){
        for(auto it: ans[i]){
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}