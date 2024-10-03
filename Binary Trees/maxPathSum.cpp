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
    int findMaxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        maxPathSum(root, maxi);
        return maxi;
    }
    int maxPathSum(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;

        int leftPathSum = maxPathSum(root->left, maxi);
        int rightPathSum = maxPathSum(root->right, maxi);

        if (leftPathSum < 0)
            leftPathSum = 0;

        if (rightPathSum < 0)
            rightPathSum = 0;

        maxi = max(maxi, root->val + leftPathSum + rightPathSum);

        return (root->val + max(leftPathSum, rightPathSum));
    }
};

int main()
{
    // write here.
}