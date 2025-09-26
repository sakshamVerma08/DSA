#include <bits/stdc++.h>
using namespace std;

int searchPosition(vector<int> nums, int target)
{

    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (high >= low)
    {

        int mid = (low + high) / 2;

        if (nums[mid] >= target)
        {
            high = mid - 1;
            ans = mid;
        }

        else
            low = mid + 1;
    }

    return ans;
}

int main()
{

    return 0;
}