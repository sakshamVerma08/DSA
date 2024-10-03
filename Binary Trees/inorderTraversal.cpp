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

    void InorderTraversal(TreeNode *root)
    { // Inorder Traversal Using Iteration

        if (root == nullptr)
        {
            return;
        }

        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr != nullptr || !st.empty())
        {

            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            cout << curr->val << "  ";
            curr = curr->right;
        }
    }
};

int main(){

    // write here.
}