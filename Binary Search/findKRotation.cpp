#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1, ans = 0;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < arr[ans])
                ans = low;

            low = mid + 1;
        }

        if (arr[mid] <= arr[high])
        {

            if (arr[mid] <= arr[ans])
                ans = mid;

            high = mid - 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};
    cout << "TC1 = " << findKRotation(nums) << endl;

    vector<int> nums2 = {0, 1, 2, 3, 4, 5, 6};
    cout << "TC 2 = " << findKRotation(nums2) << endl;

    return 0;
}