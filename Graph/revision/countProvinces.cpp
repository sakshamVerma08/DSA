#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int n;

private:
    void dfs(vector<vector<int>> &adjMatrix, vector<int> &visited, int node)
    {

        visited[node] = 1;

        for (int j = 0; j < n; j++)
        {
            // looping for columns.
            if (adjMatrix[node][j] == 1 && visited[j] != 1)
            {
                dfs(adjMatrix, visited, j);
            }
        }
    }

public:
    Solution()
    {
    }
    int findCircleNum(vector<vector<int>> &adjMatrix)
    {
        this->n = adjMatrix.size();
        int ans = 0;

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i])
                {
                    dfs(adjMatrix, visited, i);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> adjMatrix;
    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        string s;
        getline(cin, s);
        int num;
        stringstream ss(s);

        while (ss >> num)
        {
            row.push_back(num);
        }
        adjMatrix.push_back(row);
    }

    Solution *s = new Solution();
    int ans = s->findCircleNum(adjMatrix);
    cout << "ans = " << ans << endl;
    return 0;
}