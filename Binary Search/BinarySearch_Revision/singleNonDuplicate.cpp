#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int singleElement1(vector<int> &nums)
{

    if (nums.size() == 1)
        return nums[0];

    // Edge case 1: If n == 1, return the single element present.

    for (int i = 0; i < nums.size(); i++)
    {

        if (i == 0)
        {
            // Edge case 2: If i == 1, then we check if the next element is equal or not. If it's not equal, we know for sure that
            // element at index 0 is a single element in this array.

            if (nums[i] != nums[i + 1])
                return nums[i];
        }

        if (i == nums.size() - 1)
        {

            if (nums[nums.size() - 1] != nums[i])
                return nums[i];
        }

        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
            return nums[i];
    }
}

int singleElement2(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
        return nums[0];

    int ans = 0;

    for (auto it = nums.begin(); it != nums.end(); it++)
    {

        ans = ans ^ *it;
    }

    return ans;
}

int singleElement3(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
        return 1;

    if (nums[0] != nums[1])
        return nums[0];

    else if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];

    int low = 1, high = n - 2;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
            return nums[mid];

        if (mid % 2 != 0)
        {
            // Assume that we're standing in left half.
            if (nums[mid] == nums[mid - 1])
                low = mid + 1;

            // If not, then we are in the right half.

            else
                high = mid - 1;
        }

        if (mid % 2 == 0)
        {

            // Assume for left half.
            if (nums[mid] == nums[mid + 1])
                low = mid + 1;

            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 8, 8};

    cout << "ans1 = " << singleElement1(nums) << endl;
    cout << " ans2 = " << singleElement2(nums) << endl;
    cout << " ans3 = " << singleElement3(nums) << endl;

    return 0;
}