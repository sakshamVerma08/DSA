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
};

int main()
{
    int arr[] = {1, 2, 3, 7, 6, 4, 5};
    int N = sizeof(arr) / sizeof(arr[3]);

    Solution sol;
    TreeNode *root = sol.constructTree(arr, N);
    auto ans = sol.iterativeInorderTraversal(root);
    sol.printVector(ans);
    return 0;
}