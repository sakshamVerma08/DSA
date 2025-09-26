#include <bits/stdc++.h>
using namespace std;

int findLowerBound(vector<int> nums, int x)
{

    int low = 0;
    int high = nums.size() - 1;

    while (high >= low)
    {

        int mid = (low + high) / 2;

        if (nums[mid] >= x)
            return mid;

        else
            low = mid + 1;
    }

    return nums.size();
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    int x1 = 2;

    vector<int> num2 = {1, 2, 2, 3};
    int x2 = 2;

    cout << findLowerBound(nums, x1) << endl;
    cout << findLowerBound(num2, x2) << endl;

    return 0;
}