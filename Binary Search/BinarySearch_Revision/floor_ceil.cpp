#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute Force
pair<int, int> getFloorAndCeil1(vector<int> &a, int n, int x)
{
    int floor = -1;

    for (auto it = a.begin(); it != a.end(); it++)
    {

        if (*it <= x)
            floor = *it;
    }

    int ceil = -1;

    for (auto it = a.begin(); it != a.end(); it++)
    {

        if (*it >= x)
        {
            ceil = *it;
            break;
        }
    }

    return {floor, ceil};
}

pair<int, int> getFloorAndCeil2(vector<int> &nums, int n, int x)
{

    pair<int, int> ans = {-1, -1};

    int floor = -1;
    int low = 0, high = nums.size() - 1;

    // Getting floor in O(log n)
    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] <= x)
        {
            floor = nums[mid];
            low = mid + 1;
        }

        else
            high = mid - 1;
    }

    // Getting Ceil in O(log n)
    int ceil = -1;
    int ceiling_low = 0, ceiling_high = nums.size() - 1;

    while (ceiling_high >= ceiling_low)
    {

        int ceiling_mid = ceiling_low + (ceiling_high - ceiling_low) / 2;

        if (nums[ceiling_mid] >= x)
        {
            ceil = nums[ceiling_mid];
            ceiling_high = ceiling_mid - 1;
        }

        else
            ceiling_low = ceiling_mid + 1;
    }

    ans.first = floor;
    ans.second = ceil;

    return ans;
}
int main()
{

    vector<int> arr = {2, 3, 5, 6, 9, 10};
    int x = 23;

    pair<int, int> ans = getFloorAndCeil2(arr, arr.size(), x);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}