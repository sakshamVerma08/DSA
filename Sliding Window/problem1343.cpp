#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// uses sliding window algorithm
// time complexity: O(N)
// space complexity : O(1)
int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    unordered_map<int, int> freq;

    while (j < arr.size())
    {

        freq[arr[j]]++;

        int len = j - i + 1;

        if (len < k)
        {
            j++;
            continue;
        }

        else if (len == k)
        {

            int sum = 0;
            for (auto &p : freq)
            {
                sum += (p.first * p.second);
            }

            if (sum / k >= threshold)
                cnt++;

            j++;
        }

        else
        {

            freq[arr[i]]--;
            if (freq[arr[i]] == 0)
                freq.erase(arr[i]);

            i++;
            int sum = 0;
            for (auto &p : freq)
            {
                sum += (p.first * p.second);
            }

            if (sum / k >= threshold)
                cnt++;

            j++;
        }
    }

    return cnt;
}
int main()
{

    return 0;
}