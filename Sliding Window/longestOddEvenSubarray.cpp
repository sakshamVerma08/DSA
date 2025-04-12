#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(N)
// space complexity : O(1)
int longestAlternatingSubarray(vector<int> &nums, int threshold)
{
    int ans = 0;
    int n = nums.size();
    int end = 0;

    while (end < n)
    {
        if (nums[end] % 2 == 0 && nums[end] <= threshold)
        {
            // now we start to slide the window. To simulate the window sliding inside the array. we don't use the end pointer, otherwise it will messup the ending of current window in our array, instead we assing value of end to a 'temp' variable.
            int temp = end;
            while (temp + 1 < n && nums[temp] % 2 != nums[temp + 1] % 2 && nums[temp + 1] <= threshold)
            {
                temp++;
            }

            ans = max(ans, temp - end + 1);
            // we reassign start of the window to end + 1, because once our subarray is broken, there is no point to scane other elements of that subarray, so we start from end + 1.
            end = temp + 1;
        }

        else
        {
            end++;
        }
    }

    return ans;
}
int main()
{

    return 0;
}