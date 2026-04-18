#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    int m, n;
    vector<vector<int>> pacific, atlantic, visited1, visited2;
    int row[4] = {0, -1, 0, 1};
    int col[4] = {-1, 0, 1, 0};

public:
    Solution(int m, int n)
    {
        this->m = m;
        this->n = n;

        this->pacific = vector<vector<int>>(m, vector<int>(n, 0));
        this->atlantic = vector<vector<int>>(m, vector<int>(n, 0));
        this->visited1 = vector<vector<int>>(m, vector<int>(n, 0));
        this->visited2 = vector<vector<int>>(m, vector<int>(n, 0));
    }

    void dfs(vector<vector<int>> &heights, vector<vector<int>> &arr, int sr, int sc, vector<vector<int>> &visited)
    {
        visited[sr][sc] = 1;
        arr[sr][sc] = 1;
        int currentHeight = heights[sr][sc];
        for (int i = 0; i < 4; i++)
        {
            int R = sr + row[i], C = sc + col[i];

            if (R >= m || R < 0 || C >= n || C < 0 || visited[R][C] || heights[R][C] < currentHeight)
                continue;

            dfs(heights, arr, R, C, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> res;

        // Top row elements can reach pacific ocean. Similarly bottom row cells can reach atlantic ocean, so we mark them as true  in their respective 'visited' matrix.
        for (int j = 0; j < n; j++)
        {
            // looping from 0 to col-1 (inclusive).
            pacific[0][j] = 1;

            atlantic[m - 1][j] = 1;
        }

        // Left column cells can reach pacific ocean, and right column cells can reach atlantic ocean, so we mark them as visited in their respective 'visited' matrix.
        for (int i = 0; i < m; i++)
        {
            // looping from 0 to row-1 (inclusive).
            pacific[i][0] = 1;

            atlantic[i][n - 1] = 1;
        }

        // For pacific ocean, we will start DFS from (0,1). We are not starting from (0,0) because it's the first node, which is on the extreme boundary of the matrix. To it's down will always be a true cell, and to it's right will always be a true cell. The only side to which a false cell can lie is it's diagonal, which we are not to consider for this problem.

        // For top row.

        for (int j = 1; j < n; j++)
        {
            dfs(heights, pacific, 0, j, visited1);
        }

        // for last row.
        for (int j = 1; j < n; j++)
        {
            dfs(heights, atlantic, m - 1, j, visited2);
        }

        // for left col
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0, visited1);
        }

        for (int i = 0; i < m; i++)
        {
            dfs(heights, atlantic, i, n - 1, visited2);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back(vector<int>{i, j});
            }
        }
        return res;
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
    int m, n;
    cin >> m >> n;
    vector<vector<int>> heights(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> heights[i][j];
        }
    }

    Solution *s = new Solution(m, n);
    auto res = s->pacificAtlantic(heights);
    s->printRes(res);
    return 0;
}