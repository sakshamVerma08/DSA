#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count1(vector<int> &arr, int n, int x)
{

    int count = 0;

    for (auto it = arr.begin(); it != arr.end(); it++)
    {

        if (*it == x)
            count++;
    };

    return count;
};
// Brute Force
// TC) O(N)

int getFirst(vector<int> &arr, int n, int x)
{

    int ans = n, low = 0, high = n - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}

int getLast(vector<int> &arr, int n, int x)
{

    int ans = n, low = 0, high = n - 1;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return ans;
}

int count2(vector<int> &arr, int n, int x)
{

    int first = getFirst(arr, n, x);
    int last = getLast(arr, n, x);

    if (first == n || arr[first] != x)
        return 0;

    return (last - first);
}

int main()
{

    vector<int> arr = {1, 1, 1, 2, 2, 3, 3};
    int x = 3;

    cout << "count = " << count2(arr, arr.size(), x) << endl;

    return 0;
}