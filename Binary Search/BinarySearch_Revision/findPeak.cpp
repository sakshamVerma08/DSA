#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPeak1(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;

    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    for (int i = 1; i < n - 2; i++)
    {

        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return i;
    }
}

int findPeak2(vector<int> &nums)
{

    int n = nums.size();

    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;

    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int low = 1, high = n - 2;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;

        if (nums[mid] > nums[mid - 1])
        {
            // We are standing on a linearly increasing line.
            // So we can assume that the peak lies on the right. So we eliminate the left half.

            low = mid + 1;
        }

        // This means that the previous element is greater than the mid element, so we are standing on
        // a linearly decreasing line.
        // So we can safely assume that the peak lies to the left, so we eliminate the right half.
        else
            high = mid - 1;
    }

    return -1;
}
int main()
{

    vector<int> arr = {1, 2, 1, 3, 4, 5, 6, 1};

    cout << "ans = " << findPeak2(arr) << endl;

    return 0;
}