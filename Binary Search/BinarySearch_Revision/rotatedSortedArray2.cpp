#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;

        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
        }

        else if (nums[low] <= nums[mid])
        {
            // This means that the left half is sorted.

            if (nums[low] <= target && target <= nums[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }

        else
        {

            if (nums[mid] <= target && target <= nums[high])
                low = mid + 1;

            else
                high = mid - 1;
        }
    }

    return false;
}

int main()
{

    vector<int> arr = {1, 0, 1, 1};
    int target1 = 0;

    cout << "ans = " << search(arr, target1) << endl;

    return 0;
}