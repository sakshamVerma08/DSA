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

        // Left part is sorted.
        if (nums[low] <= nums[mid])
        {

            // Element is present.
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

    return -1;
}

int main()
{

    vector<int> t1 = {4, 5, 6, 7, 0, 1, 2};
    int x1 = 3;

    cout << "TC 1= " << search(t1, x1) << endl;

    return 0;
}