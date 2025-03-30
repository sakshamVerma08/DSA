#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute force approach (Hashing + Prefix Sum approach)
// time complexity : O(N)
// space complexity: O(N)
int numberOfSubarrays1(vector<int> &nums, int k)
{
    int currSum = 0, subarrays = 0;
    unordered_map<int, int> prefixSum;

    prefixSum[currSum] = 1;

    for (auto &elem : nums)
    {
        currSum += elem % 2;

        if (prefixSum.find(currSum - k) != prefixSum.end())
        {
            subarrays += prefixSum[currSum - k];
        }

        prefixSum[currSum] += 1;

    }

    return subarrays;
}

int numberOfSubarrays2(vector<int> &nums, int k)
{
}

int main()
{

    return 0;
}