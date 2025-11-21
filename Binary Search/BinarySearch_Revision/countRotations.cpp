#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countRotations(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1, smallest = INT_MAX, ans = INT_MAX;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid])
        {

            if (arr[low] < smallest)
            {
                ans = low;
                smallest = arr[low];
            }

            low = mid + 1;
        }

        else
        {

            if (arr[mid] < smallest)
            {
                ans = mid;
                smallest = arr[mid];
            }

            high = mid - 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> arr = {5, 1, 2};

    cout << "ans = " << countRotations(arr) << endl;
    return 0;
}