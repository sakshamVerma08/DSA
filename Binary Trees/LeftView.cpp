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

    // BRUTE FORCE APPROACH
    vector<int> leftView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        map<int, TreeNode *> m;
        queue<pair<int, TreeNode *>> nodes;
        nodes.push({0, root});

        while (!nodes.empty())
        {
            auto topPair = nodes.front();
            nodes.pop();
            TreeNode *curr = topPair.second;
            int Row = topPair.first;

            if (m.find(Row) == m.end())
                m[Row] = curr;

            if (curr->left)
                nodes.push({Row + 1, curr->left});

            if (curr->right)
                nodes.push({Row + 1, curr->right});
        }

        for (auto &elem : m)
        {
            ans.push_back(elem.second->val);
        }

        return ans;
    }

    void printVector(vector<int> &ans)
    {
        for (int &elem : ans)
        {
            cout << elem << " ";
        }

        cout << "\n";
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    Solution sol;
    auto root = sol.constructTree(arr, N);
    auto ans = sol.leftView(root);
    sol.printVector(ans);

    return 0;
}