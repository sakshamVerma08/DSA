#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> constructAdjList(int n, int m)
{

    vector<vector<int>> list(n); // graph starting node is 0. So we take 'n' sized adjacency list.

    for (int i = 0; i < m; i++)
    {
        // Looping from 0 to m-1 to grab edge information.
        int u, v;
        cin >> u >> v;

        list[u].emplace_back(v); // An edge u->v in undirected graph means that there exists an edge v->u as well.
        list[v].emplace_back(u);
    }

    return list;
}

void helper(vector<vector<int>> &adjList, vector<int> &res, vector<int> &visited, int node)
{
    visited[node] = 1;
    res.push_back(node);

    if (adjList[node].empty())
        return;

    vector<int> &vec = adjList[node];
    for (const int &n : vec)
    {
        if (!visited[n])
        {
            helper(adjList, res, visited, n);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adjList, vector<int> &visited)
{
    vector<int> res;
    helper(adjList, res, visited, 0);
    return res;
}

void printVec(vector<int> &vec)
{
    for (const int &n : vec)
    {
        cout << n << " ";
    }
    cout << "\n";
}
int main()
{
    int n, m;
    cout << "Enter no of nodes:" << endl;
    cin >> n;
    cout << "Enter no of edges:" << endl;
    cin >> m;

    auto adjList = constructAdjList(n, m);

    vector<int> visited(n, 0);
    vector<int> res = dfs(adjList, visited);
    printVec(res);
    return 0;
}
