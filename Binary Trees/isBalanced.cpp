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
    int findHeight(TreeNode *root)
    { // This function helps isBalanced function to check if the tree is balanced or not.

        int leftHeight = 0, rightHeight = 0;
        if (root == nullptr)
            return 0;

        leftHeight = findHeight(root->left);
        rightHeight = findHeight(root->right);

        if (leftHeight == -1 || rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return (max(leftHeight, rightHeight) + 1);
    }

    bool isBalanced(TreeNode *root)
    {

        return !(findHeight(root) == -1);
    }
};

int main(){

    // write here.
}