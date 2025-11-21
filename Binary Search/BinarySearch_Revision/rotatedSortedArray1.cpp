#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        /*
        1. Now we will check which half (either left or right half) is sorted.
        2. Once we know which half is sorted, we will check whether our target lies in that sorted half or not.
        3. If the target lies inside the sorted half, only then will we eliminate the other half. otherwise we will choose the other half.

        */

        if (nums[low] <= nums[mid])
        {
            // This means that the Left half is sorted.
            if (nums[low] <= target && target <= nums[mid])
            {
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        else
        {

            if (nums[mid] <= target && target <= nums[high])
            {
                low = mid + 1;
            }

            else
                high = mid - 1;
        }
    }

    return -1;
}

int main()
{

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int t1 = 2;

    cout << "ans = " << search(arr, t1) << endl;

    return 0;
}