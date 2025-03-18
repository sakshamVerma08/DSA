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

int longestSubarrayWithSumK3(vector<int> a, long long k)
{
}
int main()
{

    vector<int> tc1 = {8, 15, 17, 0, 11};
    int n1 = tc1.size();

    cout << "tc1 : " << longestSubarrayWithSumK(tc1, n1) << endl;

    return 0;
}