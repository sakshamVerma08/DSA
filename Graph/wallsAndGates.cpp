#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int imax = INT_MAX;

class Solution
{
private:
    using pp = pair<int, int>;
    int row[4] = {0, -1, 0, 1};
    int col[4] = {-1, 0, 1, 0};
    int m, n;

public:
    Solution()
    {
    }

    void bfs(vector<vector<int>> &grid, queue<pair<pp, int>> &q)
    {

        while (!q.empty())
        {
            int dist = q.front().second;
            int r = q.front().first.first, c = q.front().first.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newR = r + row[i];
                int newC = c + col[i];

                if (newR >= m || newC >= n || newR < 0 || newC < 0 || grid[newR][newC] != imax)
                    continue;
                // Replace the current cells value with the minimum value between current dist + 1 VS value at cell.
                grid[newR][newC] = min(grid[newR][newC], dist + 1);
                q.push({{newR, newC}, grid[newR][newC]});
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>> &grid)
    {
        queue<pair<pp, int>> q;
        // pair<pp,int> = {{row,col}, distance}

        int m = grid.size(), n = grid[0].size();
        this->m = m;
        this->n = n;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    q.push({pp{i, j}, 0});
                }
            }
        }

        bfs(grid, q);
    }
};

int main()
{

    Solution *s = new Solution();
    vector<vector<int>> grid = {{imax, -1, 0, imax}, {imax, imax, imax, -1}, {imax, -1, imax, -1}, {0, -1, imax, imax}};
    s->islandsAndTreasure(grid);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}