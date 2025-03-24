#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity: O(N^3)
// Space Complexity: O(1)
int minimumSumSubarray(vector<int> &nums, int l, int r)
{

    int minSum = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i; j < nums.size(); j++)
        {
            if ((j - i + 1) < l || (j - i + 1) > r)
                continue;

            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }
            if (sum > 0 && sum < minSum)
                minSum = sum;
        }
    }

    if (minSum == INT_MAX)
        return -1;

    return minSum;
}

// Better Approach
// Time complexity: O(N^2)
// space complexity: O(1)
int minimumSumSubarray2(vector<int> &nums, int l, int r)
{

    int minSum = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {

        int sum = 0;

        for (int j = i; j < nums.size(); j++)
        {

            if ((j - i + 1) < l)
            {
                sum += nums[j];
            }

            else if ((j - i + 1) > r)
                continue;

            else
            {

                sum += nums[j];

                if (sum > 0 && sum < minSum)
                    minSum = sum;
            }
        }
    }

    return (minSum == INT_MAX ? -1 : minSum);
}

// Uses a helper() function, and Sliding window approach
// Time complexity:O(N * (r-l+1))
// Space complexity: O(1)

// The (r-l+1) factor in time complexity is because of the loop in the main function. In that loop, basically we are
// checking for each subarray of size l to r (ex. either size =2 , size = 3 , size = 4 etc. etc.), and finding the minimum Sum
// and updating the answer accordingly.

// the helper() function returns the minimum sum of a subarray.
int helper(vector<int> &nums, int k)
{

    int sum = 0;
    int n = nums.size();

    // Forming the first sliding window, so later we can directly append the new element and delete the last element from the window in O(1) time.
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    int mini = INT_MAX;
    int left = 0;
    int right = k - 1;

    while (right < n)
    {
        if (sum > 0)
            mini = min(mini, sum);

        if (right + 1 < n)
            sum += nums[right + 1] - nums[left];

        left++;
        right++;
    }

    return mini;
}
int minimumSumSubarray3(vector<int> &nums, int l, int r)
{
}

int main()
{

    return 0;
}