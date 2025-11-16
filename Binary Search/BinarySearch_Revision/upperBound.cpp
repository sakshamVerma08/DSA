#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int upperBound1(vector<int> &arr, int x)
{

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] > x)
            return i;
    }

    return arr.size();
}

// TC) O(N)
// SC) O(1)

int upperBound2(vector<int> &arr, int x)
{

    int ans = arr.size(), low = 0, high = arr.size() - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] <= x)
            low = mid + 1;

        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> arr1 = {1, 2, 13, 16, 19, 23, 25, 29, 36, 69, 74};
    int x1 = 42;

    cout << upperBound2(arr1, x1) << "\n";
    return 0;
}