#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(log n base 2)
// space complexity : O(1)

int lowerBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int mid, ans = n;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return mid;
}

// The second way to find lower bound is to use C++ STL function lower_bound()
// example: int lb = lower_bound(vec.begin(),vec.end(), n) - vec.begin()

// We subtract the 'begin' iterator because lower_bound returns an iterator value, so after subtracting, we get the actual index.