#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Leetcode problem no 1984

// We sort the array, the slide a window of size k through the array, then look at the difference between highest and lowest element in every window of size 'k'.

// diff = nums[high] - nums[low]. Since the array is sorted, it's guaranteed that for each window, element at last index is highest, and element at start of window is lowest.

// time complexity: O(N logN) + O(N) => O(N logN)
// space complexity: O(1)
int minimumDifference(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 1)
        return 0;

    sort(nums.begin(), nums.end());

    int ans = INT_MAX;
    int low = 0;
    int high = k - 1;

    while (high < n)
    {

        ans = min(ans, nums[high] - nums[low]);
        low++;
        high++;
    }

    return ans;
}

int main()
{

    return 0;
}