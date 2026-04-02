#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    Solution()
    {
    }

    vector<vector<int>> buildPrefixSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));

        // Keeping PrefixSum matrix as 1-indexed.
        for (int r = 1; r < m; r++)
        {

            for (int c = 1; c < n; c++)
            {

                prefixSum[r][c] = prefixSum[r - 1][c] + prefixSum[r][c - 1] - prefixSum[r - 1][c - 1] + grid[r - 1][c - 1];
            }
        }

        return prefixSum;
    }

    void printGrid(vector<vector<int>> &grid)
    {

        for (const auto &v : grid)
        {
            for (const int &n : v)
            {
                cout << n << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{

    vector<vector<int>> ans;
    ans = {{11, 3, 5, 7, 9, 13}, {15, 17, 19, 21, 23, 25}, {39, 82, 6, 66, 11, 32}, {41, 1, 2, 8, 22, 39}, {42, 0, 37, 21, 90, 81}};

    Solution s;
    auto prefixSum = s.buildPrefixSum(ans);
    s.printGrid(prefixSum);

    return 0;
}