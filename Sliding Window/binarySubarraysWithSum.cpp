#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    unordered_map<int, int> prefixSumCount;
    int sum = 0, cnt = 0;

    // Initialize the map with a prefix sum of 0
    prefixSumCount[0] = 1;

    for (int num : nums)
    {
        sum += num;

        // Check if there exists a prefix sum that satisfies the condition
        if (prefixSumCount.find(sum - goal) != prefixSumCount.end())
        {
            cnt += prefixSumCount[sum - goal];
        }

        // Update the prefix sum count
        prefixSumCount[sum]++;
    }

    return cnt;
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << "Number of subarrays with sum " << goal << ": " << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}
int main()
{

    return 0;
}