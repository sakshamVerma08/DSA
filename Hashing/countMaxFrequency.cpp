#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Uses sliding window and sorting approach
// time complexity: O(N logN)
// space complexity: O(1)
int maxFrequency(vector<int> &nums, int k)
{

    sort(nums.begin(), nums.end());
    // O(logN)

    long L = 0, R = 0, total = 0, res = 0;

    while (R < nums.size())
    {

        total += nums[R];

        // Window Shrinking Loop (Invalid Window)
        while (nums[R] * (R - L + 1) > total + k)
        {
            total -= nums[L];
            L++;
            continue;
        }

        // Window Expanding part (Valid Window)
        res = max(res, R - L + 1);
        R++;
    }

    return res;
}