#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lowerBound1(vector<int> &arr, int x)
{

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] >= x)
            return i;
    }

    return arr.size();
};

// TC) O(N)
// SC) O(1)

int lowerBound2(vector<int> &arr, int x)
{

    // Because it is lower bound, we are searching for an index in the array where the element at that index is either greater than the 'x' or equal to 'x'.
    // So we can use Binary search and during the typical BS code, we can define conditions about when to return the index.

    int low = 0;
    int high = arr.size() - 1;
    int tempAns = INT_MIN;

    while (high >= low)
    {

        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
        {
            tempAns = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    if (tempAns != INT_MIN)
        return tempAns;

    else
        return arr.size();
}

int main()
{

    vector<int> arr = {1, 2, 2, 3};
    int x = 0;

    cout << lowerBound2(arr, x) << endl;

    return 0;
}