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

void getParentPointers(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent_track){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();

        if(temp->left){
            parent_track[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right){
            parent_track[temp->right] = temp;
            q.push(temp->right);
        }
    }
}

vector<int> getAllNodesDK(TreeNode *root, TreeNode *target, int k){
    // create a map for parent pointers
    unordered_map<TreeNode*, TreeNode*> parent_track;
    getParentPointers(root, parent_track);

    queue<TreeNode*> q;
    unordered_map<TreeNode*, bool> visited;
    q.push(target);
    visited[target] = true;
    int distance=0;
    while(!q.empty()){
        int size = q.size();
        if(distance==k) break;
        distance++;

        for (int i = 0; i < size; i++)
        {
            TreeNode* temp = q.front();
            q.pop();

            // left and not visited
            if(temp->left && !visited[temp->left]){
                q.push(temp->left);
                visited[temp->left] = true;
            }
            // right and not visited
            if(temp->right && !visited[temp->right]){
                q.push(temp->right);
                visited[temp->right]= true;
            }
            // top and not visited
            if(parent_track[temp] && !visited[parent_track[temp]]){
                q.push(parent_track[temp]);
                visited[parent_track[temp]] = true;
            }
        }
    }

    // final answer present in queue
    vector<int> ans;
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
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

    vector<int> ans = getAllNodesDK(root, root->left, 1);
    for(auto it: ans){
        cout << it << " ";
    }

    return 0;
}