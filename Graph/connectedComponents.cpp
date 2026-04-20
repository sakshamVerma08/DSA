#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    Solution()
    {
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
    {
        
    }

    void printRes(vector<vector<int>> &res)
    {
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = 0; j < res[0].size(); j++)
            {
                cout << res[i][j] << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V;
    int E;
    cin >> V >> E; // taking number of vertices and edges as input.

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        // looping from 0 to e-1 (inclusive).
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<int> tmp;
        int vertice;

        while (ss >> vertice)
        {
            tmp.push_back(vertice);
        }

        edges.push_back(tmp);
    }

    Solution *s = new Solution();
    auto res = s->getComponents(V, edges);
    s->printRes(res);
    return 0;
}