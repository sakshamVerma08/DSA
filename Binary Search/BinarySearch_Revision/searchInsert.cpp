#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{

    int low = 0, high = nums.size() - 1;
    int ans = nums.size();

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}

int main()
{

    vector<int> n1 = {1, 3, 5, 6};
    int t1 = 5;

    vector<int> n2 = {1, 3, 5, 6};
    int t2 = 2;

    cout << "t1 = " << searchInsert(n1, t1) << endl;
    cout << " t2 = " << searchInsert(n2, t2) << endl;

    return 0;
}