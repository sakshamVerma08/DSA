#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{

    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        left = NULL;
        right = NULL;
    }

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void printVector(vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
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

    void LeftBoundary(vector<int> &v, TreeNode *root)
    {
        // Gets the left boundary nodes of the Binary Tree, excluding the leaf nodes.

        // This condition ensures that even those nodes are scanned which only have one child.
        while (root != nullptr && (root->left != nullptr || root->right != nullptr))
        {
            v.push_back(root->data);

            if (root->left)
                root = root->left;

            else if (root->right)
                root = root->right;
        }
    }

    void BottomBoundary(vector<int> &v, TreeNode *root)
    // Gets the leaf nodes or the bottom boundary nodes of the Binary Tree.
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
        {
            // Checks if there is duplication of node in the answer array.
            if (find(v.begin(), v.end(), root->data) == v.end())
                v.push_back(root->data);
        }

        BottomBoundary(v, root->left);
        BottomBoundary(v, root->right);
    }
    void RightBoundary(vector<int> &v, TreeNode *root)
    {
        // Gets the right boundary nodes of the Binary Tree, excluding the leaf nodes and in the Reverse Order.
        stack<int> st;

        // This condition ensures that even those nodes are scanned which have only one child.
        while (root != nullptr && (root->left != nullptr || root->right != nullptr))
        {
            st.push(root->data);
            if (root->right)
                root = root->right;

            else if (root->left)
                root = root->left;
        }

        while (!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
    }

    vector<int> BoundaryTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        ans.push_back(root->data);

        LeftBoundary(ans, root->left);
        BottomBoundary(ans, root);
        RightBoundary(ans, root->right);

        return ans;
    }
};

int main()
{

    int bt1[] = {1, 2, 7, 3, -1, -1, 8, -1, 4, 9, -1, 5, 6, 10, 11};
    int N = sizeof(bt1) / sizeof(bt1[0]);
    Solution s;
    TreeNode *root = s.constructTree(bt1, N);

    vector<int> ans = s.BoundaryTraversal(root);

    s.printVector(ans);

    return 0;
}