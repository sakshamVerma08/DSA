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

int minimumSumSubarray3(vector<int> &nums, int l, int r)
{
}

int main()
{

    return 0;
}