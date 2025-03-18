#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Using brute force solution (select each and every subarray and check for it)
// time complexity: O(N^3)
// space complexity: O(1)

// First loop takes all starting indexes of all subarrays
// Second loop takes all ending indexes of all subarrays
// The third loop is suppossed to loop inside a particular subarray of size arr[i,j].

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int length = 0;
    int sum;

    for (int i = 0; i < a.size(); i++)
    {

        for (int j = i; j < a.size(); j++)
        {

            sum = 0;
            // for each subarray
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }

            if (sum == k)
                length = max(length, j - i + 1);
        }
    }

    return length;
}

// Optimized Brute force solution
// time complexity: O(N^2)
// space complexity: O(1)
int longestSubarrayWithSumK2(vector<int> a, long long k)
{
    int length = 0;
    int sum;

    for (int i = 0; i < a.size(); i++)
    {

        sum = 0;

        for (int j = i; j < a.size(); j++)
        {

            sum += a[j];

            if (sum > k)
                break;

            else if (sum == k)
            {
                length = max(length, j - i + 1);
                continue;
            }
        }
    }

    return length;
}

// Better Approach (works for both non-negative numbers and integers)
// Time complexity:
// If using ordered map: O(N*logN)
// If using unordered map: O(N)
// Unordered map worst case: O(N^2)

// Space complexity: O(N)
int longestSubarrayWithSumK3(vector<int> a, long long k)
{
    map<long long, int> mpp;
    int maxLen = 0;
    long long sum = 0;

    for (int i = 0; i < a.size(); i++)
    {

        sum += a[i];

        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }

        long long rem = sum - k;
        if (mpp.find(rem) != mpp.end())
        {
            int len = i - mpp[rem];
            maxLen = max(maxLen, len);
        }

        if (mpp.find(sum) == mpp.end())
        {
            mpp[sum] = i;
        }
    }

    return maxLen;
}

// Optimized Solution (Two Pointer Approach)
// Time complexity:O(2N) => O(N)
// Space complexity: O(1)
int longestSubarrayWithSumK4(vector<int> a, long long k)
{
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;

    while (right < a.size())
    {

        while (sum > k && left <= right)
        {
            sum -= a[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;

        if (right < a.size())
        {
            sum += a[right];
        }
    }

    return maxLen;
}

int main()
{

    vector<int> tc1 = {10, 1, 17, 10, 11};
    vector<int> tc2 = {2, 0, 0, 3};
    long long k1 = 11;
    long long k2 = 3;

    cout << "tc1 : " << longestSubarrayWithSumK4(tc1, k1) << endl;
    cout << "tc2 : " << longestSubarrayWithSumK4(tc2, k2) << endl;

    return 0;
}