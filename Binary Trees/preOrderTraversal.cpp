#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    TreeNode *constructTree(int arr[], int N)
    {

        if (N == 0)
            return nullptr;

        TreeNode *root = new TreeNode(arr[0]);
        queue<TreeNode *> q1;
        q1.push(root);

        int i = 1;

        while (i < N)
        {

            auto currentNode = q1.front();
            q1.pop();

            if (i < N && arr[i] != -1)
            {
                currentNode->left = new TreeNode(arr[i]);
                q1.push(currentNode->left);
            }
            i++;

            if (i < N && arr[i] != 1)
            {
                currentNode->right = new TreeNode(arr[i]);
                q1.push(currentNode->right);
            }

            i++;
        }

        return root;
    }

    void iterativepreOrderTraversal(TreeNode *root)
    { // Pre Order Traversal Using Iteration

        if (root == NULL)
        {
            return;
        }

        stack<TreeNode *> TreeNodeStack;
        TreeNodeStack.push(root);

        while (!TreeNodeStack.empty())
        {

            TreeNode *topTreeNode = TreeNodeStack.top();
            cout << topTreeNode->val << " ";
            TreeNodeStack.pop();

            if (topTreeNode->right)
                TreeNodeStack.push(topTreeNode->right);

            if (topTreeNode->left)
                TreeNodeStack.push(topTreeNode->left);
        }
    }
};

int main()
{

    // write here.
}