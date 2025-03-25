#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Leetcode problem 594

// Brute force Solution
// time complexity: O(NlogN + N^2) => O(N^2)
// space complexity: O(1)
int findLHS(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 0;
    }
    int ans = INT_MIN;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {

        int cnt = 1;

        for (int j = i + 1; j < nums.size(); j++)
        {

            if (nums[j] - nums[i] <= 1)
            {
                cnt++;

                if (nums[j] - nums[i] == 1)
                    ans = max(ans, cnt);
            }

            else if (nums[j] - nums[i] > 1)
                break;

            else
                continue;
        }
    }

    return (ans == INT_MIN ? 0 : ans);
}

// Time complexity : O(N)
// space complexity : O(N)
int findLHS2(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (auto &elem : nums)
    {
        freq[elem]++;
    }

    int ans = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {

        if (freq.find(nums[i] + 1) != freq.end())
        {
            ans = max(ans, freq[nums[i]] + freq[nums[i] + 1]);
        }
    }

    return (ans == INT_MIN ? 0 : ans);
}
int main()
{

    vector<int> v = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "tc1 = " << findLHS2(v) << endl;

    return 0;
}