#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min(vector<int> &arr)
{
    int ans = INT_MAX, low = 0, high = arr.size() - 1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high])
        {
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid])
        {
            // This means that the Left half is sorted. We will check for our most minimum element in the other half, but before that, we need to capture the minimum element from this half, so we use the property that this half is sorted.
            ans = min(ans, arr[low]);
            low = mid + 1;
        }

        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }

    return ans;
}
int main()
{
    vector<int> arr = {3, 4, 5, 6, 7, 1, 2};

    cout << "ans = " << min(arr) << endl;
    return 0;
}