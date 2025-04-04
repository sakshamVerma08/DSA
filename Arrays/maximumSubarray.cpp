#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time complexity: O(N^3)
// space complexity: O(1)
int maxSubArray(vector<int> &nums)
{
    int ans = INT_MIN, sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i; j < nums.size(); j++)
        {

            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += nums[k];
            }

            ans = max(ans, sum);
        }
    }

    return ans;
}

int maxSubArray2(vector<int> &nums)
{

    int ans = INT_MIN;
    int sum = 0;

    int N = nums.size();

    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += nums[j];
            ans = max(ans, sum);
        }
    }

    return ans;
}

// using Kadane's algorithm
// time complexity :O(N)
// space complexity: O(1)
int maxSubArray3(vector<int> &nums)
{
    long long sum = 0;
    long maximumSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];

        if (sum > maximumSum)
            maximumSum = sum;

        if (sum < 0)
            sum = 0;
    }

    return maximumSum;
}
int main()
{

    vector<int> tc1 = {0, 1, -3, 4, 5};
    cout << "tc1 = " << maxSubArray2(tc1) << endl;
    return 0;
}