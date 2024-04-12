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

string serialize(TreeNode *root){
    if(!root) return "";
    string ans="";
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();

        if(temp==NULL) ans.append("#,");
        else ans.append(to_string(temp->data)+',');

        if(temp!= NULL){
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return ans;
}

TreeNode* deserialize(string data){
    if(data.length()==0){
        return NULL;
    }

    stringstream ss(data);
    string str;
    getline(ss, str, ',');

    TreeNode *root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *temp = q.front();
        q.pop();

        getline(ss, str, ',');
        if(str == "#"){
            temp->left = NULL;
        }else{
            TreeNode *left = new TreeNode(stoi(str));
            temp->left = left;
            q.push(left);
        }

        getline(ss, str, ',');
        if(str == "#"){
            temp->right = NULL;
        }else{
            TreeNode *right = new TreeNode(stoi(str));
            temp->right = right;
            q.push(right);
        }
    }
    return root;
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

    string ser = serialize(root);
    cout << ser << endl;

    TreeNode *r = deserialize(ser);
    cout << r->data;
    return 0;
}