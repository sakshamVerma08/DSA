#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int m, n;
    int row[4] = {0, -1, 0, 1};
    int col[4] = {-1, 0, 1, 0};

    void dfs(vector<vector<char>> &grid, int sr, int sc)
    {

        grid[sr][sc] = '0'; // Don't flip this cell to 'X' in the final loop.

        for (int i = 0; i < 4; i++)
        {
            int newR = sr + row[i];
            int newC = sc + col[i];

            if (newR >= m || newC >= n || newR < 0 || newC < 0 || grid[newR][newC] != 'O')
                continue;

            dfs(grid, newR, newC);
        }
    }

public:
    Solution()
    {
    }
    void solve(vector<vector<char>> &grid)
    {
        this->m = grid.size(), this->n = grid[0].size();

        // Loop for Top Row. i = 0
        for (int j = 0; j < n; j++)
        {
            // looping for 0 to col-1 (inclusive).
            if (grid[0][j] == 'O')
            {
                dfs(grid, 0, j);
            }
        }

        // For Last Row, i = m-1.
        for (int j = 0; j < n; j++)
        {
            if (grid[m - 1][j] == 'O')
            {
                dfs(grid, m - 1, j);
            }
        }

        // For Left Column, j = 0.
        for (int i = 0; i < m; i++)
        {

            if (grid[i][0] == 'O')
            {
                dfs(grid, i, 0);
            }
        }

        // For Right Column, j = n-1.
        for (int i = 0; i < m; i++)
        {

            if (grid[i][n - 1] == 'O')
            {
                dfs(grid, i, n - 1);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                    grid[i][j] = 'O';
                else
                    grid[i][j] = 'X';
            }
        }
    }
};

int main()
{
    vector<vector<char>> grid = {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};
    Solution *s = new Solution();
    s->solve(grid);
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