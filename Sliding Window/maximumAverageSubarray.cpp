#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(N)
// space complexity :O(1)
double findMaxAverage(vector<int> &nums, int k)
{
    double maxAvg = numeric_limits<double>::lowest();
    double windowSum = 0;

    for (int i = 0; i < k; i++)
    {
        windowSum += nums[i];
    }

    maxAvg = windowSum / k;

    for (int i = k; i < nums.size(); i++)
    {
        windowSum += nums[i];
        windowSum -= nums[i - k];

        double newAvg = windowSum / k;
        maxAvg = max(maxAvg, newAvg);
    }

    return maxAvg;
}
int main()
{
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;

    cout << "tc1 = " << findMaxAverage(nums1, k1) << endl;

    return 0;
}