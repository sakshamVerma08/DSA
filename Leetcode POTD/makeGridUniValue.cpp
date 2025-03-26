#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// brute force approach
// time complexity: O(m * n * logmn)
// space complexity: O(1)
int minOperations(vector<vector<int>> &grid, int x)
{
    vector<int> arr;

    for (auto &elem : grid)
    {
        int i = 0;
        while (i < elem.size())
        {
            arr.push_back(elem[i]);
            i++;
        }
    }

    sort(arr.begin(), arr.end());
    int result = 0;

    int median = arr[arr.size() / 2];

    for (auto &num : arr)
    {
        if (num % x != median % x)
            return -1;

        else
        {
            result += abs(median - num) / x;
        }
    }

    return result;
}

int main()
{

    return 0;
}