#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity: O(N)
// space complexity: O(1)
int findLHS(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int left = 0, right = 1;
    int ans = 0;
    int n = nums.size();

    while (right < n)
    {

        if (nums[right] - nums[left] == 1)
        {
            ans = max(ans, right - left + 1);
        }

        else if (nums[right] - nums[left] == 0)
        {
            right++;
            continue;
        }

        else
        {
            // shrink the window

            while (right - left + 1 > 1 && nums[right] - nums[left] != 1)
            {
                left++;
            }

            if (nums[right] - nums[left] == 1)
                ans = max(ans, right - left + 1);
        }

        right++;
    }

    return ans;
}

int main()
{

    return 0;
}