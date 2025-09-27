#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &nums, int x)
{

    int low = 0;
    int ans = -1;
    int high = nums.size() - 1;

    while (high >= low)
    {
        int mid = (low + high) / 2;

        if (nums[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }

        else
            low = mid + 1;
    }

    cout << " Index = " << ans << endl;
}

int main()
{

    vector<int> v1 = {3, 4, 5, 6, 7};
    int x1 = 2;

    lowerBound(v1, x1);
    return 0;
}