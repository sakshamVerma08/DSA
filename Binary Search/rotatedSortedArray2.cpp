#include <bits/stdc++.h>
using namespace std;

int search2(vector<int> &nums, int target)
{

    int low = 0, high = nums.size() - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low += 1;
            high -= 1;
            continue;
        }

        if (nums[low] <= nums[mid])
        {

            if (nums[low] <= target && target <= nums[mid])
                high = mid - 1;

            else
                low = mid + 1;
        }

        if (nums[high] >= nums[mid])
        {

            if (nums[high] >= target && target >= nums[mid])
                low = mid + 1;

            else
                high = mid - 1;
        }
    }

    return false;
}

int main()
{

    vector<int> v1 = {2, 5, 6, 0, 0, 1, 2};
    int t1 = 0;

    cout << "T1 = " << search2(v1, t1) << endl;

    return 0;
}