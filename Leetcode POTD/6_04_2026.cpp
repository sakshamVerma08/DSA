#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int m, n;
    vector<vector<char>> ans;

public:
    Solution()
    {
    }
    void rotateTheBox(vector<vector<char>> &mat)
    {
        this->m = mat.size(), this->n = mat[0].size();
        this->ans = vector<vector<char>>(n, vector<char>(m, ' '));

        for (int r = 0; r < m; r++)
        {
            // [0,m-1].

            int ptr = n - 1;
            for (int i = n - 1; i >= 0; i--)
            {
                // [n-1, 0].

                if (mat[r][i] == '*')
                {
                    ptr = i - 1;
                }

                else if (mat[r][i] == '#')
                {
                    mat[r][ptr] = '#';

                    if (ptr != i)
                        mat[r][i] = '.';

                    ptr--;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[j][m - 1 - i] = mat[i][j];
            }
        }
    }

    void printAns()
    {
        cout << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[0].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<vector<char>> mat;
    int m, n;
    cin >> m >> n;
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);

        vector<char> row;
        char c;
        while (ss >> c)
        {
            row.emplace_back(c);
        }

        mat.emplace_back(row);
    }

    Solution *s = new Solution();
    s->rotateTheBox(mat);
    s->printAns();

    return 0;
}