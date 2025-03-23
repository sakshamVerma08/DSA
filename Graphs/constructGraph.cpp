#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
int main()
{ // This is using Adjacency Matrix
    // Time complexity: O(m)
    // Space complexity: O(N^2)
    // n is no of vertices & m is no of edges.

    int n, m;

    cout << "Enter no of vertices: " << endl;
    cin >> n;
    cout << "Enter number of edges: " << endl;
    cin >> m;

    int adj[n + 1][n + 1];

    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    return 0;
}

*/

int main()
{

    int n, m;
    cout << "Enter no of vertices: " << endl;
    cin >> n;
    cout << "Enter no of edges: " << endl;
    cin >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {

        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}