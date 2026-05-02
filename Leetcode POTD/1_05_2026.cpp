#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int ans = INT_MIN;

public:
    Solution()
    {
    }
    int maxRotateFunction(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        int f0 = 0;

        for (int i = 0; i < n; i++)
        {
            // looping from 0 to (n-1) (inclusive).
            sum += arr[i];
            f0 += (i * arr[i]);
        }

        int res = f0;

        for (int k = 0; k < n; k++)
        {
            // looping from 0 to (n-1) (inclusive).
            int newF = f0 + sum - n * arr[n - 1 - k];

            res = max(res, newF);
            f0 = newF;
        }

        return res;
    }

    vector<int> rotate_array_by_k(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            // looping from 0 to n-1 (inclusive).
            int newIdx = (i + k) % n;
            ans[newIdx] = arr[i];
        }
        return ans;
    }
};

int main()
{
    Solution *s = new Solution();
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    auto ans = s->rotate_array_by_k(arr, k);
    for (const int &n : ans)
    {
        cout << n << ",";
    }
    cout << endl;
    return 0;
}