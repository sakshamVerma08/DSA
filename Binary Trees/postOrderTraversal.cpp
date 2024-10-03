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
    vector<int> postOrderTraversal(TreeNode *root)
    { // Post Order Traversal Using 2 Stacks

        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        st1.push(root);

        while (!st1.empty())
        {

            root = st1.top();
            st1.pop();
            st2.push(root);

            if (root->left)
                st1.push(root->left);

            if (root->right)
                st1.push(root->right);
        }

        while (!st2.empty())
        {

            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }

    vector<int> postOrderTraversal2(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<TreeNode *> st;
        TreeNode *curr = root;
        TreeNode *temp;

        while (!st.empty() || curr != nullptr)
        {
            // curr is used to check whether the left childTreeNode is null or not
            if (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            // if curr is null, we check the rightTreeNode child, if that is not null, we assign curr = temp, but if it is null, then we pop from stack and then check if the partiular TreeNode has a root or not.
            else
            {
                temp = st.top()->right;

                if (temp == nullptr)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    // this while loop helps to jump from the child to the parent TreeNode/ or to find if a particular TreeNode has a root/parent TreeNode or not.
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }

                else
                {
                    curr = temp;
                }
            }
        }

        return ans;
    }
};