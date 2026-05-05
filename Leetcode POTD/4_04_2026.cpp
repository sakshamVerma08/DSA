#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int imax = INT_MAX;

public:
    Solution()
    {
    }

    void rotate(vector<vector<int>> &matrix)
    {
        
    }

    vector<vector<int>> rotate2(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> columns;

        for (int c = 0; c < n; c++)
        {
            vector<int> col;
            for (int r = 0; r < n; r++)
            {
                col.push_back(matrix[r][c]);
            }
            columns.push_back(col);
        }

        vector<vector<int>> ans(n);

        for (int r = 0; r < n; r++)
        {
            reverse(columns[r].begin(), columns[r].end());
            ans[r] = columns[r];
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> matrix;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int num;
        while (ss >> num)
        {
            row.emplace_back(num);
        }
        matrix.emplace_back(row);
    }

    Solution *s = new Solution();
    auto ans = s->rotate2(matrix);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}