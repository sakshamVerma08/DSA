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
        left = nullptr, right = nullptr;
    }

    TreeNode(int val)
    {
        this->val = val;
        left = nullptr, right = nullptr;
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

    vector<int> postOrderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
        {
            ans.push_back(-10e4 - 1);
            return ans;
        }

        vector<int> left = postOrderTraversal(root->left);
        vector<int> right = postOrderTraversal(root->right);

        for (int i = 0; i < right.size(); i++)
        {
            left.push_back(right[i]);
        }

        left.push_back(root->val);

        return left;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {

        vector<int> post1 = postOrderTraversal(p);
        vector<int> post2 = postOrderTraversal(q);

        return (post1 == post2);
    }
};

int main()
{   // write here.
}