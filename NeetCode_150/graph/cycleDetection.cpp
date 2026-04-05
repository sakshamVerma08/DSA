#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdjList(int n, int m)
{
    vector<vector<int>> adj_list(n + 1, vector<int>{});

    for (int i = 0; i < m; i++)
    {
        // looping from 0 to m-1 (inclusive).
        int u, v;
        cin >> u >> v;
        adj_list[u].emplace_back(v);
        adj_list[v].emplace_back(u);
    }
    return adj_list;
}

bool detectCycle(vector<vector<int>> &adjList, vector<int> &visited, int start)
{

    queue<pair<int, int>> q;
    q.push({start, -1});

    while (!q.empty())
    {
        int node = q.front().first, parent = q.front().second;
        q.pop();
        visited[node] = 1;

        for (int &n : adjList[node])
        {
            // Runs for all the adjacent vertices for the current vertex.

            if (!visited[n])
            {
                visited[n] = 1;
                q.push({n, node});
            }
            // means the current adjacent node is visited, and if it's not the parent, then we know that we visited this node from another path, hence confirming the existence of a cycle.
            else if (parent != n)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    vector<vector<int>> adjList;

    int n, m, start;
    cout << "Enter no of nodes:" << endl;
    cin >> n;
    cout << endl
         << "Enter number of edges:" << endl;
    cin >> m;

    adjList = constructAdjList(n, m);
    vector<int> visited(n + 1, 0);

    cout << "Enter the starting node:" << endl;
    cin >> start;

    bool ans = false;
    for (int i = 1; i <= n; i++)
    {

        if (!visited[i])
        {
            if (detectCycle(adjList, visited, i))
            {
                ans = true;
                break;
            }
        }
    }

    (ans == true) ? cout << "cycle is present" << endl : cout << "cycle is not present" << endl;

    return 0;
}