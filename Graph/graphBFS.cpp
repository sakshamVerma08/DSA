#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList(int n, int m)
{
    vector<vector<int>> l(n + 1, vector<int>{});

    for (int i = 0; i < m; i++)
    {
        // looping from 0 to m-1 (inclusive).
        int u, v;

        cin >> u;
        cin >> v;

        l[u].emplace_back(v);
        l[v].emplace_back(u);
    }

    return l;
}

void printAdjList(vector<vector<int>> &adjList)
{
    cout << endl;
    for (int i = 1; i < adjList.size(); i++)
    {

        cout << to_string(i) + "--->";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << ",";
        }
        cout << endl;
    }
    cout << endl;
}
int main()
{

    int n, m;
    cout << "Enter no of nodes:" << endl;
    cin >> n;
    cout << endl
         << "Enter no of edges:" << endl;
    cin >> m;

    auto adj_list = adjList(n, m);
    printAdjList(adj_list);
    return 0;
}
