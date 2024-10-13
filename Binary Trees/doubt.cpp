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
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int val)
    {

        this->val = val;
        left = nullptr;
        right = nullptr;
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

    vector<int> iterativeInorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> nodes;
        auto curr = root;

        while (!nodes.empty() || curr != nullptr)
        {

            // GO LEFT UNTIL YOU CAN'T
            while (curr)
            {
                nodes.push(curr);
                curr = curr->left;
            }

            // When done going left , pop from the stack to come to the parent node. Add the value of parent node to the answer array.
            curr = nodes.top();
            nodes.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }

        return ans;
    }

    void printVector(vector<int> &ans)
    {
        for (int elem : ans)
        {
            cout << elem << " ";
        }

        cout << endl;
    }

    vector<int> postOrderTraversal2(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        auto curr = root;
        stack<TreeNode *> st;

        while (!st.empty() || curr != nullptr)
        {

            // Go Left until you can't
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }

            // If you can't go left , that means you have to now visit the right Subtree.
            else
            {
                auto temp = st.top()->right;

                if (temp == nullptr)
                { // If right subtree is NULL, the we have sccanned both left and right, and now we have to push
                    // the current parent node, which is at top of the stack.
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    // After this we have to check if the current parent nodes' both trees have been visited  or not,
                    // the new 'current parent node' will be at top of stack.

                    // If the right subtree has not been visited, then this while loop will not be executed.
                    // The job of this while loop is to keep backtracking.

                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }

                // If it is not NULL , just point curr to right subtree.
                else
                {
                    curr = temp;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 7, 6, 4, 5};
    int N = sizeof(arr) / sizeof(arr[3]);

    Solution sol;
    TreeNode *root = sol.constructTree(arr, N);
    auto ans = sol.postOrderTraversal2(root);
    sol.printVector(ans);
    return 0;
}