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

    vector<vector<int>> levelOrderTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode *> q1;
        q1.push(root);

        while (!q1.empty())
        {

            vector<int> arr;
            int size = q1.size();
            for (int i = 0; i < size; i++)
            {

                auto temp = q1.front();
                q1.pop();

                if (temp->left)
                    q1.push(temp->left);

                if (temp->right)
                    q1.push(temp->right);

                arr.push_back(temp->val);
            }

            ans.push_back(arr);
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