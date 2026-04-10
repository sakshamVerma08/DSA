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

    vector<int> topo_sort_bfs()
    {
        vector<int> ans;
        vector<int> indegree(n, 0);
        // This indegree stores the information about each node's indegree, that is , for a particular node, how many nodes are directing edges to that node.
        // The use of this indegree array is to track when a node's indegree becomes 0, then we can push that node in the queue, and hence in our linear ordering.
        // The way to build this indegree is to use the adjacency list. Since the adjacency list is defined as u->{neighbors of u}, so when we reach 'u', we can do a ++increment in the indegree of all the neighbors of u, because u is directing an edge to all it's neighbors.
        for (int i = 0; i < n; i++)
        {
            // looping from 0 to n-1 (inclusive).
            for (const int &num : adjList[i])
            {
                indegree[num]++;
            }
        }

        queue<int> q;
        // We will firstly traverse the indegree, and we can push all the nodes which have an indegree of zero.
        // I can do this because a node which has an indegree of zero doesn't have any 'u' node that is directing an edge towards it, so we can place the node with indegree zero at the very beginning of the linear ordering, since it doesn't have to be "ahead" of some u value. So we add such a value in our queue.
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (indegree[node] == 0)
                ans.push_back(node);

            for (const int &num : adjList[node])
            {
                // I will try to eliminate the directed edges that this particular node has to other vertices, by reducing the indegree of it's neighbor nodes.
                indegree[num]--;
                if (indegree[num] == 0)
                    q.push(num);
            }
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
    Graph *g = new Graph(6, 6);
    g->constructAdjList();
    auto v = g->topo_sort_bfs();
    g->printArr(v);
    return 0;
}