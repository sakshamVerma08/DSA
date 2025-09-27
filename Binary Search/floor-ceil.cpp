#include <bits/stdc++.h>
using namespace std;

void floor_ceil(vector<int> nums, int x)
{

    int floor = INT_MIN;
    int ceil = INT_MAX;

    int low = 0;
    int high = nums.size() - 1;

    while (high >= low)
    {

        int mid = (low + high) / 2;

        if (nums[mid] <= x)
        {
            floor = nums[mid];
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
            ceil = nums[mid];
        }
    }

    if (ceil == INT_MAX)
        ceil = -1;
    if (floor == INT_MIN)
        floor = -1;

    cout << "Floor = " << floor << endl
         << "Ceil = " << ceil << endl;
}

int main()
{

    vector<int> v1 = {1, 2, 3, 4, 5};
    int x1 = 6;

    floor_ceil(v1, x1);
    return 0;
}