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

    int diameter = 0;
    int findHeightofTree(TreeNode *root)
    { // Finds the Height of the Binary tree

        if (root == nullptr)
            return 0;

        int leftHeight, rightHeight;
        leftHeight = findHeightofTree(root->left);
        rightHeight = findHeightofTree(root->right);

        // Updating the overall diameter of the tree
        diameter = max(diameter, leftHeight + rightHeight);

        return (max(leftHeight, rightHeight) + 1);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == 0)
            return 0;

        findHeightofTree(root);
        return diameter;
    }
};

int main()
{

    // write here.
}