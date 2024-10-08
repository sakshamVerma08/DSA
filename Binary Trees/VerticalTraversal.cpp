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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;

        // Queue stores value as follows : (Node, (Row, Column)).
        queue<pair<TreeNode *, pair<int, int>>> nodeQueue;

        // Map is as follows: {Col : {Row: {multiset containing all the nodes of the row}}}.
        map<int, map<int, multiset<int>>> nodes;

        nodeQueue.push({root, {0, 0}});

        while (!nodeQueue.empty())
        {

            auto topPair = nodeQueue.front();
            nodeQueue.pop();
            auto topNode = topPair.first;

            int Col = topPair.second.second;
            int Row = topPair.second.first;

            // We are accessing the inner map using nodes[Col].
            // Then we are accessing the Multiset of that particular row using nodes[Col][Row] and inserting the node value for
            // current node.
            nodes[Col][Row].insert(topNode->val);

            if (topNode->left)
                nodeQueue.push({topNode->left, {Row + 1, Col - 1}});

            if (topNode->right)
                nodeQueue.push({topNode->right, {Row + 1, Col + 1}});
        }

        // We are iterating for each elem in the map "nodes". So elem is kind of equal to the inner map,
        // that is map<int , multiset<int>>
        for (auto &elem : nodes)
        {
            vector<int> column;

            // We are iterating in the multiset using elem.second, so elem.second = multiset<int>.
            for (auto &innerElem : elem.second)
            {
                column.insert(column.end(), innerElem.second.begin(), innerElem.second.end());
            }

            ans.push_back(column);
        }

        return ans;
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

    void printVectorOfVectors(const vector<vector<int>> &vec)
    {
        for (const auto &elem : vec)
        {

            for (const auto &innerElem : elem)
            {
                cout << innerElem << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[1]);

    TreeNode *root = s.constructTree(arr, N);

    auto ans = s.verticalTraversal(root);
    s.printVectorOfVectors(ans);
    return 0;
}