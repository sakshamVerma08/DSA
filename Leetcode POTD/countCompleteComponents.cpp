#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, unordered_map<int, vector<int>> &adj, vector<bool> &visited, int &v, int &e)
    {

        visited[i] = true;

        v++;
        e += adj[i].size();

        for (int &ngbr : adj[i])
        {
            if (!visited[ngbr])
            {
                dfs(ngbr, adj, visited, v, e);
            }
        }
    }

    // Optimized Approach.
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        // Initialize Union Find and edge counter
        UnionFind dsu(n);
        unordered_map<int, int> edgeCount;

        // Connect components using edges
        for (const auto &edge : edges)
        {
            dsu.unionSets(edge[0], edge[1]);
        }

        // Count edges in each component
        for (const auto &edge : edges)
        {
            int root = dsu.find(edge[0]);
            edgeCount[root]++;
        }

        // Check if each component is complete
        int completeCount = 0;
        for (int vertex = 0; vertex < n; vertex++)
        {
            if (dsu.find(vertex) == vertex)
            { // If vertex is root
                int nodeCount = dsu.size[vertex];
                int expectedEdges = (nodeCount * (nodeCount - 1)) / 2;
                if (edgeCount[vertex] == expectedEdges)
                {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }

    // Using DFS Traversal
    int countCompleteComponents2(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        // Unordered map is used to represent adjacency list.

        int result = 0;
        // building the graph
        for (auto &elem : edges)
        {
            int u = elem[0];
            int v = elem[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true)
                continue;

            int v = 0;
            int e = 0;
            dfs(i, adj, visited, v, e);

            if (v * (v - 1) / 2 == e / 2)
            {
                result++;
            }
        }

        return result;
    }

    int countCompleteComponents3(int n, vector<vector<int>> &edges)
    {
    }

private:
    class UnionFind
    {
    public:
        vector<int> parent;
        vector<int> size; // Tracks size of each component

        UnionFind(int n) : parent(n, -1), size(n, 1) {}

        // Find root of component with path compression
        int find(int node)
        {
            if (parent[node] == -1)
            {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union by size
        void unionSets(int node1, int node2)
        {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2)
            {
                return;
            }

            // Merge smaller component into larger one
            if (size[root1] > size[root2])
            {
                parent[root2] = root1;
                size[root1] += size[root2];
            }
            else
            {
                parent[root1] = root2;
                size[root2] += size[root1];
            }
        }
    };
};

int main()
{

    // test in coding platforms like leetcode/code360 etc.
    return 0;
}