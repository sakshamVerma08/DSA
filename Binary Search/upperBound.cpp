#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &nums, int x)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int mid, ans = n;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (nums[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    return mid;
}

/*  Similar to lower bound, C++ STL has upper_bound() function

int x = upper_bound(v.begin(),v.end(),n) - v.begin()
*/
int main()
{

    return 0;
}