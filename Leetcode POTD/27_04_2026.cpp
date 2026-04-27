#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool ans;
    int m, n;
    vector<vector<int>> visited;

    unordered_map<int, vector<vector<int>>> mpp = {
        {1, {{0, -1}, {0, 1}}},
        {2, {{-1, 0}, {1, 0}}},
        {3, {{0, -1}, {1, 0}}},
        {4, {{0, 1}, {1, 0}}},
        {5, {{0, -1}, {-1, 0}}},
        {6, {{-1, 0}, {0, 1}}}};

    bool dfs(vector<vector<int>> &grid, int sr, int sc)
    {

        if (sr == m - 1 && sc == n - 1)
            return true;

        visited[sr][sc] = 1;
        int street_num = grid[sr][sc];

        for (auto &dir : mpp[street_num])
        {
            int newR = sr + dir[0];
            int newC = sc + dir[1];

            if (newR < 0 || newC < 0 || newR >= m || newC >= n || visited[newR][newC])
                continue;

            // check if you can come back from (newR,newC) to (sr,sc).

            for (auto &back_dir : mpp[grid[newR][newC]])
            {
                if (newR + back_dir[0] == sr && newC + back_dir[1] == sc)
                {
                    if (dfs(grid, newR, newC))
                        return true;
                }
            }
        }

        return false;
    }

public:
    Solution()
    {
    }
    bool hasValidPath(vector<vector<int>> &grid)
    {
        this->m = grid.size(), this->n = grid[0].size();
        this->visited = vector<vector<int>>(m, vector<int>(n, 0));

        ans = dfs(grid, 0, 0);

        return ans;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<vector<int>> grid;
    int m, n;
    cin >> m >> n;
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        vector<int> row;
        string str = "";
        getline(cin, str);
        stringstream ss(str);
        int num;

        while (ss >> num)
        {
            row.push_back(num);
        }
        grid.push_back(row);
    }

    bool ans = s->hasValidPath(grid);

    ans == true ? cout << "Valid path found" << endl : cout << "No valid path found" << endl;
    return 0;
}