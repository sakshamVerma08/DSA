#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(NlogN + N)
// space complexity: O(1)
int minimumDifference(vector<int> &nums, int k)
{
    int ans = INT_MAX;
    int left = 0, right = 0;
    sort(nums.begin(), nums.end());

    while (right < nums.size())
    {

        if (right - left + 1 < k)
        {
            right++;
            continue;
        }

        else if (right - left + 1 == k)
        {
            ans = min(ans, nums[right] - nums[left]);
        }

        else
        {
            left++;
            if (right - left + 1 == k)
                ans = min(ans, nums[right] - nums[left]);
        }

        right++;
    }

    return ans;
}

int main()
{

    return 0;
}