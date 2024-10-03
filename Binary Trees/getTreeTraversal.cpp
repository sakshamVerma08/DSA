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

    vector<vector<int>> getTreeTraversal(TreeNode *root)
    { // Get all the 3 Traversals of Tree in one pass

        vector<int> inorder, preorder, postorder;
        vector<vector<int>> ans;
        stack<pair<TreeNode *, int>> st;

        st.push({root, 1});

        while (!st.empty())
        {

            auto currentPair = st.top();
            st.pop();
            // Preorder State
            if (currentPair.second == 1)
            {
                preorder.push_back(currentPair.first->val);
                currentPair.second++;
                st.push(currentPair);

                if (currentPair.first->left)
                    st.push({currentPair.first->left, 1});
            }

            // Inorder State
            else if (currentPair.second == 2)
            {
                inorder.push_back(currentPair.first->val);
                currentPair.second++;
                st.push(currentPair);

                if (currentPair.first->right)
                    st.push({currentPair.first->right, 1});
            }

            // Post Order
            else
            {
                postorder.push_back(currentPair.first->val);
            }
        }

        ans.push_back(inorder);
        ans.push_back(preorder);
        ans.push_back(postorder);
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