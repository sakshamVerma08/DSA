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

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    { // Returns the Zig Zag Level Order Traversal  of a Binary Tree

        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        queue<TreeNode *> q1;
        bool leftToRight = true;
        q1.push(root);

        while (!q1.empty())
        {
            int size = q1.size();
            vector<int> currLevel(size);

            for (int i = 0; i < size; i++)
            {

                TreeNode *node = q1.front();
                q1.pop();

                int index = (leftToRight) ? i : (size - 1 - i);

                currLevel[index] = node->val;

                if (node->left)
                    q1.push(node->left);

                if (node->right)
                    q1.push(node->right);
            }

            ans.push_back(currLevel);
            leftToRight = !leftToRight;
        }

        return ans;
    }

    void printVectorOfVectors(const vector<vector<int>> &vec)
    { // Prints a Vector containing vectors

        for (const auto &innerVec : vec)
        {
            for (int val : innerVec)
            {
                cout << val << " ";
            }
            cout << endl; // Print a new line after each inner vector
        }
    }
};

int main()
{

    // write here.
}