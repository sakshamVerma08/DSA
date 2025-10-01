#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
        return nums[0];

    if (nums[0] != nums[1])
        return nums[0]; // First element is single element.

    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1]; // Last element is single element.

    int low = 1, high = n - 2;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
            return nums[mid];

        // eliminate left search space.
        if ((mid % 2 != 0 && nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && nums[mid + 1] == nums[mid]))
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "TC1 = " << singleNonDuplicate(nums) << endl;

    return 0;
}