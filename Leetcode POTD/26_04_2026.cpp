#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int row[4] = {0, -1, 0, 1};
    int col[4] = {-1, 0, 1, 0};
    bool ans;
    int m, n;
    vector<vector<int>> visited, pathVis;

    bool dfs(vector<vector<char>> &grid, int sr, int sc, int lastRow, int lastCol, int &cnt)
    {

        visited[sr][sc] = 1;
        pathVis[sr][sc] = 1;

        for (int i = 0; i < 4; i++)
        {
            int newR = sr + row[i];
            int newC = sc + col[i];

            if (newR < 0 || newC < 0 || newR >= m || newC >= n || (newR == lastRow && newC == lastCol) || grid[newR][newC] != grid[sr][sc])
                continue;

            if (!visited[newR][newC])
            {
                bool ans = dfs(grid, newR, newC, sr, sc, cnt += 1);
                if (ans)
                    return (cnt >= 4) ? true : false;
            }

            else if (pathVis[newR][newC])
            {
                cnt += 1;
                return (cnt >= 4) ? true : false;
            }
        }

        pathVis[sr][sc] = 0;
        cnt--;
        return false;
    }

public:
    Solution()
    {
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        this->m = grid.size(), this->n = grid[0].size();
        this->visited = vector<vector<int>>(m, vector<int>(n, 0));
        this->pathVis = vector<vector<int>>(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            int lastRow;
            lastRow = (i == 0) ? -1 : i - 1;

            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j])
                {
                    int lastCol;
                    lastCol = (j == 0) ? -1 : j - 1;

                    int cnt = 0;
                    bool ans = dfs(grid, i, j, -1, -1, cnt);
                    if (ans)
                        return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<char>> grid;
    int m, n;
    cin >> m >> n;
    cin.ignore();

    vector<char> row;

    for (int i = 0; i < m; i++)
    {
        vector<char> row;
        string r;
        getline(cin, r);
        stringstream ss(r);
        char ch;
        while (ss >> ch)
        {
            row.push_back(ch);
        }
        grid.push_back(row);
    }

    Solution *s = new Solution();

    bool ans = s->containsCycle(grid);
    if (ans)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}