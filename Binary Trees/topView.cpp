#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node()
    {
        left = nullptr;
        right = nullptr;
    }

    Node(int val)
    {
        this->data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution
{
public:
    Node *constructTree(int arr[], int N)
    {
        if (N == 0)
            return nullptr;

        Node *root = new Node(arr[0]);
        queue<Node *> q1;
        q1.push(root);

        int i = 1;

        while (i < N)
        {
            auto currentNode = q1.front();
            q1.pop();

            if (i < N && arr[i] != -1)
            {
                currentNode->left = new Node(arr[i]);
                q1.push(currentNode->left);
            }
            i++;

            if (i < N && arr[i] != -1)
            {
                currentNode->right = new Node(arr[i]);
                q1.push(currentNode->right);
            }

            i++;
        }

        return root;
    }

    void helperFunction(Node *root, vector<int> &ans)
    {
        // Contains the node value and the column in which node is located as a pair
        //  (nodeVal, column).
        queue<pair<int, Node *>> nodeQueue;

        // Contains all the column as keys with their node values as values.
        map<int, Node *> m;
        nodeQueue.push({0, root});

        while (!nodeQueue.empty())
        {
            auto topPair = nodeQueue.front();
            nodeQueue.pop();
            Node *curr = topPair.second;
            int Col = topPair.first;

            // If left exists for current root, push it by decrementing the column by 1.
            if (curr->left)
                nodeQueue.push({Col - 1, curr->left});

            // If right exists for current root, push it by incrementing the column by 1.
            if (curr->right)
                nodeQueue.push({Col + 1, curr->right});

            // If a node for the current column does not exist in map, then add it.
            if (m.find(Col) == m.end())
            {
                m.insert({Col, curr});
            }
            // If the pair is found for a column, then no need to scan it, just skip.
            else
            {
                continue;
            }
        }

        for (auto elem : m)
        {
            ans.push_back(elem.second->data);
        }
    }

    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        helperFunction(root, ans);
        return ans;
    }

    void printVector(vector<int> &ans)
    {
        for (int val : ans)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Example usage
    Solution sol;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    Node *root = sol.constructTree(arr, 7);
    vector<int> topViewResult = sol.topView(root);

    sol.printVector(topViewResult);

    return 0;
}