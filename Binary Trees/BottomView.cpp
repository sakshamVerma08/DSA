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
    void printVector(vector<int> &ans)
    {
        for (int elem : ans)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
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

            if (i < N && arr[i] != 1)
            {
                currentNode->right = new Node(arr[i]);
                q1.push(currentNode->right);
            }

            i++;
        }

        return root;
    }

    vector<int> bottomView(Node *root)
    {

        vector<int> ans;
        if (root == nullptr)
            return ans;

        map<int, int> nodes;
        queue<pair<Node *, int>> nodeQueue;

        int Col;
        nodeQueue.push({root, 0});

        while (!nodeQueue.empty())
        {

            auto topPair = nodeQueue.front();
            nodeQueue.pop();

            Node *curr = topPair.first;
            Col = topPair.second;

            nodes[Col] = curr->data;

            if (curr->left)
                nodeQueue.push({curr->left, Col - 1});

            if (curr->right)
                nodeQueue.push({curr->right, Col + 1});
        }

        for (auto elem : nodes)
        {
            ans.push_back(elem.second);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int arr[] = {20, 8, 22, 5, 3, 4, 25, -1, -1, 10, -1, -1, 14};
    int N = sizeof(arr) / sizeof(arr[1]);
    Node *root = sol.constructTree(arr, N);
    auto ans = sol.bottomView(root);

    sol.printVector(ans);

    return 0;
}
