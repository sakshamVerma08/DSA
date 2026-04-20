#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int imax = INT_MAX;

class Solution
{
private:
    int V, E;

public:
    Solution(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void dfs(int node, vector<vector<pair<int, int>>> &adjList, vector<int> &visited, stack<int> &st)
    {

        visited[node] = 1;

        for (const auto &p : adjList[node])
        {
            // p = {node, edge wt}
            int adjNode = p.first;

            if (!visited[adjNode])
            {
                dfs(adjNode, adjList, visited, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestDistance(vector<vector<pair<int, int>>> &adjList)
    {
        vector<int> visited(this->V, 0);
        vector<int> distance(this->V, imax);
        distance[0] = 0;

        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            // looping from 0 to V-1 (inclusive) for all nodes in graph.
            if (!visited[i])
            {
                dfs(i, adjList, visited, st);
            }
        }

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (const auto &p : adjList[node])
            {
                int v = p.first;
                int wt = p.second;

                if (distance[node] + wt < distance[v])
                    distance[v] = distance[node] + wt;
            }
        }

        for (int &d : distance)
        {
            if (d == imax)
                d = -1;
        }

        return distance;
    }

    void printVec(vector<int> &vec)
    {
        for (const auto &tmp : vec)
        {
            cout << tmp << ",";
        }
        cout << endl;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adjList(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // An edge from u -> v with a wt of w.
        adjList[u].push_back({v, w});
    }

    Solution *s = new Solution(V, E);
    auto vec = s->shortestDistance(adjList);
    s->printVec(vec);

    return 0;
}