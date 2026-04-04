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

vector<int> bfs(vector<vector<int>> &adjList, vector<int> &visited, int start)
{
    vector<int> res;
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty())
    {
        // Looping until the queue becomes empty.
        int node = q.front();
        q.pop();
        res.emplace_back(node);

        vector<int> &v = adjList[node];
        for (const int &n : v)
        {
            if (!visited[n])
            {
                q.push(n);
                visited[n] = 1;
            }
        }
    }

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
    cout << "Enter no of Vertices:" << endl;
    cin >> n;
    cout << endl
         << "Enter no of Edges:" << endl;
    cin >> m;

    auto adjList = constructAdjList(n, m);

    vector<int> visited(n, 0);
    vector<int> res = bfs(adjList, visited, 9);
    printVec(res);
    return 0;
}
