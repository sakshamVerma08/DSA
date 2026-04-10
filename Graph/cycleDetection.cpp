#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DFS
{
private:
    int n;
    int m;
    bool dfs(vector<vector<int>> &adjList, vector<int> &vis, vector<int> &pathVis, int node, int parent)
    {

        vis[node] = 1;
        pathVis[node] = 1;

        for (const int &num : adjList[node])
        {

            if (!vis[num])
            {
                bool tmp = dfs(adjList, vis, pathVis, num, node);
                if (tmp)
                    return true;
            }
            else if (pathVis[num])
                return true;
        }

        // While returning after visiting a node, I will mark it unvisited in pathVis[node] array. This is because now we are backtracking to a previous node, and the current node will simply not exist on our current path, so why should we keep it marked falsly in our pathVis array. So we mark it as zero.
        // But we have touched it, so we don't change the visited status for this node.
        pathVis[node] = 0;
        return false;
    }

public:
    DFS(int n, int m)
    {
        this->n = n;
        this->m = m;
    }
    bool canFinish(int n, vector<vector<int>> &arr)
    {
        vector<vector<int>> adjList(n);
        for (const auto &v : arr)
        {
            adjList[v[1]].emplace_back(v[0]); // Making an edge from u to v.
        }
        vector<int> visited(n, 0);
        // Visited array is used to keep track of those nodes that our dfs algorithm has already touched. Without this visited array, we would be making extra DFS calls, or we might go into infinite DFS stack depth.
        // We don't need to call DFS again for an already visited node, because according to our DFS Induction Hypothesis, once we call DFS(i), this ensures that we visit all the adjacent nodes connected to i, so we don't need to re-visit them.

        vector<int> pathVis(n, 0);
        // Path visited is also a kind of visited array. However, it's more specific in nature. The use of this array is to simply keep track of all nodes that we have visited on the SAME PATH as we are traversing right now on. Because in a Directed Graph, the path matters as edges are pointing in a particular direction, so we keep track of all the nodes that we have visited on the same path previously.
        // If at any point of time in our DFS we encounter a node that we have visited, except the parent for the ith node that we have called DFS for, and that node also happens to be on the same path , that is pathVis[i] = 1 for that node, then we know that we have reached the same node from a different route, that means there's a cycle in our graph.

        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                bool flag = dfs(adjList, visited, pathVis, i, i - 1);
                if (flag)
                    return false;
            }
        }
        return true;
    }
};

class BFS
{
private:
    vector<vector<int>> adjList;
    vector<int> visited;
    vector<int> pathVis;
    int n;
    int m;

public:
    BFS(int n, int m)
    {
        this->n = n;
        this->m = m;
        this->adjList = vector<vector<int>>(n);
    }
    bool cycleDetection()
};