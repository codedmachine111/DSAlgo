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

vector<int> getBottomView(TreeNode *root){
    // queue (node, line)
    queue<pair<TreeNode*, int>> todo;

    // map to maintain 1 node per line <line, node_value>
    map<int, int> nodes;

    todo.push({root, 0});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        TreeNode *node = p.first;
        int line = p.second;

        nodes[line] = node->data;

        if(node->left){
            todo.push({node->left, line-1});
        }
        if(node->right){
            todo.push({node->right, line+1});
        }
    }

    vector<int> ans;
    for(auto it: nodes){
        ans.push_back(it.second);
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

    vector<int> ans = getBottomView(root);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}