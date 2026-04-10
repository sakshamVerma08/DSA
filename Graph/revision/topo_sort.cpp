#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TopoSort_BFS
{
    // 1.Now firstly, we are using a queue data structure instead of a stack data structure beause in BFS, we are actually building the linear ordering from the very start, as compared to the DFS approach, in which we were getting elements in a kind of "Post order", then using a stack to get the correct order.private : int n, m;
    // 2. We will always have nodes in our queue whose indegrees are 0. This means that for each node in our queue data structure, we will already have the 'u' elements that should come before that node in the linear ordering, that's why we can take that node out of queue, and place it directly in our ans array
    // 3. We are looping and decreasing the indegree for each adjacent node for our current node. This is because when we place it in our queue data structure, we know that the node that it's directing an edge to (the 'v' for this 'u') can be placed , but we check before pushing in queue data structure that is the indegree for this ['v'] 0 or not, because there might be some other 'u' pointing it's edge at this node
    vector<vector<int>> adjList;
    vector<int> indegree, visited;
    queue<int> q;

public:
    TopoSort_BFS(int n, int m)
    {
        this->n = n;
        this->m = m;
        this->adjList = vector<vector<int>>(n, vector<int>{});
        this->indegree = vector<int>(n, 0);
    }

    void constructAdjList()
    {
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v); // making an edge from u to v.
        }

        // Calculating the indegree for each node in graph.
        for (int i = 0; i < n; i++)
        {
            vector<int> &v = adjList[i];
            for (const int &num : v)
            {
                indegree[num]++;
            }
        }
    }

    void printAns(vector<int> &ans)
    {
        for (const int &num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> topo_sort()
    {
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            // If we ever get a node during our BFS, which has 0 indegree, that means in our linear ordering, for this node, there is no node behind it to be placed, because no 'u' exists for this node. So we just push it in our queue data structure, mark it as visited.
            // Also, since we have considered this node, so we will decrease the indegree of all neighbor nodes for this node, since this node will not be considered, so whichever node was it directing to, their indegrees will be decremented.
            for (const int &num : adjList[node])
            {
                indegree[num]--;
                if (indegree[num] == 0)
                    q.push(num);
            }
        }
        return ans;
    }
};

class TopoSort_DFS
{

private:
    vector<vector<int>> adjList;
    int n, m;
    stack<int> st;
    vector<int> visited;

    // We traverse to the deepest node that we can find, with no neighbor nodes.
    // Let's consider this as our 'u' node. We can always say that this node, at this point of time, can be placed at last in our linear ordering, so we store it in stack while backtracking to previous recursive call.
    // Let's say the previous recursive call had only the current 'u' in stack as it's adjacent node, so we can safely say that we can place the current node before 'u' that is present in the stack.

public:
    TopoSort_DFS(int n, int m)
    {
        this->n = n;
        this->m = m;
        adjList = vector<vector<int>>(n, vector<int>{});
        visited = vector<int>(n, 0);
    }

    void constructAdjList()
    {
        cout << "Start entering edges:" << endl;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v); // Pointing an edge from u -> v.
        }
    }

    void printAns(vector<int> &ans)
    {
        for (const int &num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    void dfs(int node)
    {
        visited[node] = 1;

        for (const int &num : adjList[node])
        {
            if (!visited[num])
            {
                dfs(num);
            }
        }

        st.push(node);
    }
    vector<int> topo_sort()
    {
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            // looping from 0 to n-1 (inclusive).
            if (!visited[i])
            {
                dfs(i);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main()
{

    int n1 = 7, m1 = 7;
    TopoSort_BFS *g = new TopoSort_BFS(n1, m1);
    g->constructAdjList();
    vector<int> ans = g->topo_sort();
    g->printAns(ans);

    return 0;
}