#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &nums)
{

    for (auto it = nums.begin(); it != nums.end(); it++)
    {

        cout << *it << " ";
    }

    cout << endl;
}

int getStart(vector<int> &nums, int target)
{

    int ans = nums.size(), low = 0, high = nums.size() - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}

int getEnd(vector<int> &nums, int target)
{

    int ans = nums.size(), low = 0, high = nums.size() - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{

    vector<int> ans(2, -1);

    int start = getStart(nums, target);

    if (start == nums.size() || nums[start] != target)
        return ans;

    ans[0] = start;
    ans[1] = getEnd(nums, target) - 1;

    return ans;
}

int main()
{

    vector<int> nums = {5, 7, 7, 8, 8, 8, 10};
    int target = 8;

    vector<int> ans = searchRange(nums, target);

    printVector(ans);

    return 0;
}