#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{

    int low = 0, high = nums.size() - 1, ans = INT_MAX;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[low] <= nums[mid])
        {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }

        else
        {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }

    return ans;
}
int main()
{

    vector<int> v1 = {11, 13, 15, 17};

    cout << "tc1 = " << findMin(v1) << endl;

    vector<int> v2 = {4, 5, 6, 7, 0, 1, 2};

    cout << "tc2 = " << findMin(v2) << endl;

    return 0;
}