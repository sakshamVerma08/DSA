#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(vector<vector<int>> &arr, int val)
    {

        for (const auto &v : arr)
        {

            if (val >= v[1])
                val -= v[0];

            else
                return false;
        }

        return val >= 0;
    }

public:
    Solution()
    {
    }
    int minimumEffort(vector<vector<int>> &arr)
    {
        int lowerLimit = INT_MIN;
        int upperLimit = 0;
        sort(arr.begin(), arr.end(), [&](const vector<int> &v1, const vector<int> &v2) -> bool
             { return (v1[1] - v1[0]) > (v2[1] - v2[0]); });

        for (const auto &v : arr)
        {

            if (v[1] > lowerLimit)
                lowerLimit = v[1];

            upperLimit += v[1];
        }

        int st = lowerLimit, end = upperLimit;
        int ans = 0;

        while (st <= end)
        {
            int mid = st + (end - st) / 2;

            if (check(arr, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                st = mid + 1;
        }

        return ans;
    }
};

int main()
{

    vector<vector<int>> arr;
    int n;
    int num;

    cin >> n;
    cin.ignore();

    string task;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        getline(cin, task);
        stringstream ss(task);

        while (ss >> num)
        {
            v.emplace_back(num);
        }
        arr.emplace_back(v);
    }

    Solution *s = new Solution();

    cout << "Ans = " << s->minimumEffort(arr) << endl;

    return 0;
}
