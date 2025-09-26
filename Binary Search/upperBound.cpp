#include <bits/stdc++.h>
using namespace std;

int findUpperBound(vector<int> nums, int x)
{

    int low = 0;
    int high = nums.size() - 1;

    while (high >= low)
    {

        int mid = (low + high) / 2;

        if (nums[mid] > x)
            return mid;

        else if (nums[mid] <= x)
            low = mid + 1;
    }

    return nums.size();
}

int main()
{

    vector<int> v1 = {1, 2, 3, 4, 5};
    int x1 = 1;

    vector<int> v2 = {1, 1, 1, 1, 1, 1, 2};
    int x2 = 1;

    cout << "t1 = " << findUpperBound(v1, x1) << endl;
    cout << "t2 = " << findUpperBound(v2, x2) << endl;

    return 0;
}