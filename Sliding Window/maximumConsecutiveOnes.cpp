#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(N)
// space complexity: O(1)
int longestOnes(vector<int> &nums, int k)
{

    int res = INT_MIN;
    int left = 0, right = 0;
    int zeroes = 0;
    int n = nums.size();

    for (int right = 0; right < n; right++)
    {
        if (nums[right] == 0)
            zeroes++;

        while (zeroes > k)
        {
            if (nums[left] == 0)
                zeroes--;

            left++;
        }

        res = max(res, right - left + 1);
    }

    return res;
}

int main()
{

    return 0;
}