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

vector<vector<int>> getVerticalTraversal(TreeNode *root){
    // queue (node, vertical, level)
    queue<pair<TreeNode*, pair<int,int>>> todo;

    // map to maintain the each vertical ans <v, <l, multiset_of_nodes>>
    map<int, map<int, multiset<int>>> nodes;

    todo.push({root, {0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        TreeNode *temp = p.first;
        int v = p.second.first;
        int l = p.second.second;

        nodes[v][l].insert(temp->data);

        if(temp->left){
            todo.push({temp->left, {v-1, l+1}});
        }
        if(temp->right){
            todo.push({temp->right, {v+1, l+1}});
        }
    }

    vector<vector<int>> ans;

    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }

    return ans;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);

    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    vector<vector<int>> ans = getVerticalTraversal(root);
    for(auto it: ans){
        for(auto it1: it){
            cout << it1 << " ";
        }
        cout << endl;
    }

    return 0;
}