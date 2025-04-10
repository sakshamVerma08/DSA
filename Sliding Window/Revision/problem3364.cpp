#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(n * (r-l+1))
// space complexity :O(1)
int minimumSumSubarray(vector<int> &nums, int l, int r)
{
    vector<int> prefix(nums.size() + 1, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    int mSum = INT_MAX;

    for (int k = l; k <= r; ++k)
    {
        for (int i = 0; i + k <= nums.size(); ++i)
        {
            int sum = prefix[i + k] - prefix[i];
            if (sum > 0)
                mSum = min(mSum, sum);
        }
    }

    return (mSum == INT_MAX ? -1 : mSum);
}

int main()
{

    return 0;
}