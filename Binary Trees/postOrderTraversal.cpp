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
    {
        // Returns the Post order Traversal of BT
        // using 2 Stacks.

        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            auto top = s1.top();
            s1.pop();
            s2.push(top);
            if (top->left)
                s1.push(top->left);

            if (top->right)
                s1.push(top->right);
        }

        while (!s2.empty())
        {
            auto top = s2.top();
            s2.pop();
            ans.push_back(top->val);
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

    void printVector(vector<int> &vec)
    {
        for (int elem : vec)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr1[] = {1, 2, 3, 7, 6, 4, 5};
    int N = sizeof(arr1) / sizeof(arr1[0]);
    Solution sol;
    TreeNode *root = sol.constructTree(arr1, N);
    auto ans = sol.postOrderTraversal(root);
    sol.printVector(ans);
    return 0;
}