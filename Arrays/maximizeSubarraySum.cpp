// Leetcode 3410
// FAILED

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long kadaneAlgorithm(const vector<int> &arr)
{
    if (arr.empty())
        return 0;
    long long current = arr[0];
    long long best = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        current = max((long long)arr[i], current + arr[i]);
        best = max(best, current);
    }
    return best;
}

long long maxSubarraySum(vector<int> &nums)
{

    unordered_set<int> st;
    for (auto &elem : nums)
    {
        st.insert(elem);
    }

    long long maxSum = kadaneAlgorithm(nums);
    for (auto &elem : st)
    {

        vector<int> temp;
        for (auto &x : nums)
        {
            if (x != elem)
                temp.push_back(x);
        }

        if (temp.empty())
            continue;

        long long sum = kadaneAlgorithm(temp);

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}
int main()
{

    return 0;
}