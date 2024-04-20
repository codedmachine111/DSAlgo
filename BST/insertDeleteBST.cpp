#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

TreeNode *insertNode(TreeNode *root, int val)
{
    TreeNode *newNode = new TreeNode(val);
    if (root == NULL)
    {
        return newNode;
    }

    TreeNode *cur = root;
    while (cur)
    {
        if (val > cur->data)
        {
            if (cur->right)
            {
                cur = cur->right;
            }
            else
            {
                cur->right = newNode;
                break;
            }
        }
        else
        {
            if (cur->left)
            {
                cur = cur->left;
            }
            else
            {
                cur->left = newNode;
                break;
            }
        }
    }

    return root;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        TreeNode *temp = root->right;
        if (temp)
        {
            while (temp->left)
                temp = temp->left;
            temp->left = root->left;
            return root->right;
        }
        return root->left;
    }
    return root;
}

int main()
{

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->right->right = new TreeNode(8);

    root = insertNode(root, 7);
    cout << root->right->right->left->data;

    return 0;
}