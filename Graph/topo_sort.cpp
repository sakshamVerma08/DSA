#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{ // Taking graph as starting from node 0.
private:
    int n;
    int m;
    stack<int> st;
    vector<vector<int>> adjList;
    vector<int> visited;

public:
    Graph(int n, int m)
    {
        this->n = n;
        this->m = m;
        stack<int> st;
        this->adjList = vector<vector<int>>(n);
        this->visited = vector<int>(n, 0);
    }

    void constructAdjList()
    {

        for (int i = 0; i < m; i++)
        {
            // looping from 0 to m-1 (inclusive).
            int u, v;
            cin >> u >> v;
            adjList[u].emplace_back(v); // edge going from u -> v.
        }
    }

    void dfs(int node)
    {
        visited[node] = 1;

        for (auto &num : adjList[node])
        {
            if (!visited[num])
            {
                dfs(num);
            }
        }

        this->st.push(node);
    }

    vector<int> topo_sort()
    {

        for (int i = 0; i < n; i++)
        {
            // looping from 0 to n-1 (inclusive).
            if (!visited[i])
            {
                dfs(i);
            }
        }

        vector<int> ans;
        while (!this->st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    void printArr(vector<int> &arr)
    {
        for (const int &n : arr)
        {
            cout << n << ",";
        }
        cout << endl;
    }
};

int main()
{

    Graph *g = new Graph(8, 7);
    Graph *g2 = new Graph( );
    g->constructAdjList();
    g2->constructAdjList();
    vector<int> ans = g->topo_sort();
    vector<int> ans2 = g2->topo_sort();
    g->printArr(ans2);

    return 0;
}