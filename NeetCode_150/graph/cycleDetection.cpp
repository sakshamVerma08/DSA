#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class UndirectedGraph
{
private:
    vector<vector<int>> adjList;
    vector<int> visited;
    int n, m;

public:
    UndirectedGraph(int n, int m)
    {
        this->adjList = vector<vector<int>>(n + 1, vector<int>{});
        this->visited = vector<int>(n + 1, 0);
        this->n = n;
        this->m = m;
    }

    void constructAdjList(int n, int m)
    {
        for (int i = 0; i < m; i++)
        {
            // looping from 0 to m-1 (inclusive).
            int u, v;
            cin >> u >> v;
            this->adjList[u].emplace_back(v);
            this->adjList[v].emplace_back(u);
        }
    }

    bool detectCycle_bfs(int start)
    {

        queue<pair<int, int>> q;
        q.push({start, -1});

        while (!q.empty())
        {
            int node = q.front().first, parent = q.front().second;
            q.pop();
            visited[node] = 1;

            for (int &num : adjList[node])
            {
                // Runs for all the adjacent vertices for the current vertex.

                if (!visited[num])
                {
                    visited[num] = 1;
                    q.push({num, node});
                }
                // means the current adjacent node is visited, and if it's not the parent, then we know that we visited this node from another path, hence confirming the existence of a cycle.
                else if (parent != num)
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool helper(int node, int parent)
    {

        visited[node] = 1;

        for (auto &num : adjList[node])
        {

            if (!visited[num])
            {
                bool tmp = helper(num, node);
                if (tmp)
                    return true;
            }
            else if (num != parent)
                return true;
        }
        return false;
    }

    bool detectCycle_dfs(int node, int parent)
    {
        return helper(node, parent);
    }

    bool checkComponents_dfs(int n)
    {

        for (int i = 1; i <= n; i++)
        {
            // looping from 1 to n (inclusive).
            if (!visited[i])
            {
                bool flag = detectCycle_dfs(i, -1);
                if (flag)
                    return flag;
            }
        }
        return false;
    }
    void checkComponents()
    {
        bool ans = false;
        for (int i = 1; i <= n; i++)
        {

            if (!visited[i])
            {
                if (detectCycle_bfs(i))
                {
                    ans = true;
                    break;
                }
            }
        }

        (ans == true) ? cout << "cycle is present" << endl : cout << "cycle is not present" << endl;
    }

    vector<vector<int>> getAdjList()
    {
        return this->adjList;
    }

    vector<int> getVisited()
    {
        return this->visited;
    }
};

class DirectedGraph
{
private:
    vector<vector<int>> adjList;
    vector<int> visited, pathVisited;
    int n, m;

public:
    DirectedGraph(int n, int m)
    {
        this->n = n, this->m = m;
        this->adjList = vector<vector<int>>(n + 1, vector<int>{});
        this->visited = vector<int>(n + 1, 0);
        this->pathVisited = vector<int>(n + 1, 0);
    }

    void constructAdjList()
    {
        for (int i = 0; i < m; i++)
        {
            // looping from 0 to m-1 (inclusive).
            int u, v;
            cin >> u >> v;
            this->adjList[u].emplace_back(v);
        }
    }

    bool cycleDetection_bfs()
    {
    }

    bool helper(int start)
    {

        visited[start] = 1;
        pathVisited[start] = 1;

        for (int &num : adjList[start])
        {

            if (!visited[num])
            {
                bool flag = helper(num);
                if (flag)
                    return true;
            }
            else if (pathVisited[num])
                return true;
        }
        pathVisited[start] = 0;
        return false;
    }

    bool cycleDetection_dfs()
    {
        for (int i = 1; i <= n; i++)
        {
            // looping from 1 to n (inclusive).
            if (!visited[i])
            {
                if (helper(i))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    int n, m, start;
    cout << "Enter no of nodes:" << endl;
    cin >> n;
    cout << endl
         << "Enter number of edges:" << endl;
    cin >> m;

    DirectedGraph *graph1 = new DirectedGraph(n, m);
    graph1->constructAdjList();
    if (graph1->cycleDetection_dfs())
        cout << "cycle detected" << endl;

    else
        cout << "Cycle not detected" << endl;

    return 0;
}