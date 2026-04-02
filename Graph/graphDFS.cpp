#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v)
{
    for (const int &num : v)
    {
        cout << num << " ";
    }
    cout << endl;
}
vector<vector<int>> adjList(int n, int m)
{
    vector<vector<int>> adj_list(n + 1, vector<int>{});

    for (int i = 0; i < m; i++)
    {
        // looping from 0 to m-1 (inclusive).
        int u, v;

        cin >> u;
        cin >> v;

        adj_list[u].emplace_back(v);
        adj_list[v].emplace_back(u);
    }
    return adj_list;
}

void dfs(vector<vector<int>> &adjList, vector<int> &visited, vector<int> &res, int node)
{
    visited[node] = 1;

    res.emplace_back(node);

    for (int i = 0; i < adjList[node].size(); i++)
    {
        int tmp = adjList[node][i];
        if (!visited[tmp])
            dfs(adjList, visited, res, tmp);
    }
}
int main()
{

    int n, m;
    cout << "Enter no of nodes:" << endl;
    cin >> n;
    cout << endl
         << "Enter no of Edges:" << endl;
    cin >> m;

    auto adj_list = adjList(n, m);
    vector<int> res;
    vector<int> visited(n + 1, 0);
    dfs(adj_list, visited, res, 1);
    printVec(res);
    return 0;
}
