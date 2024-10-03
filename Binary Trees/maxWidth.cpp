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

    long long maxWidth(TreeNode *root)
    {
        // 1-based Indexing is given to tree nodes.

        if (root == nullptr)
            return 0;

        queue<pair<TreeNode *, int>> q1;
        long long mWidth = 0;
        q1.push({root, 1});

        while (!q1.empty())
        {
            long long size = q1.size();
            long long first, last;
            int min;

            for (int i = 0; i < size; i++)
            {
                auto Node = q1.front();
                q1.pop();

                if (i == 0)
                {
                    first = Node.second;
                    min = Node.second;
                }

                if (i == size - 1)
                    last = Node.second;

                if (Node.first->left)
                    q1.push({Node.first->left, min - 2 * Node.second});

                if (Node.first->right)
                    q1.push({Node.first->right, min - 2 * Node.second + 1});
            }

            mWidth = max(mWidth, last - first + 1);
        }

        return mWidth;
    }
};

int main(){
    // write here.
}