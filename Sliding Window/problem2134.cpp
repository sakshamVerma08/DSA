#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// this is the optimized approach which uses space complexity O(1) without unordered map
// originally, instead of a 'zeroCnt' variable, i was using an unordered map, which would take space.

// Time complexity:O(N)
int minSwaps(vector<int> &nums)
{
    int ones = 0;
    int n = nums.size();
    for (auto &elem : nums)
    {
        if (elem == 1)
            ones++;
    }

    if (ones <= 1)
        return 0;

    int i = 0, j = 0, ans = INT_MAX, zeroCnt = 0;

    while (j < n + ones)
    {
        if (nums[j % n] == 0)
            zeroCnt++;

        if (j - i + 1 < ones)
        {
            j++;
            continue;
        }

        else if (j - i + 1 == ones)
        {
            ans = min(ans, zeroCnt);
        }

        if (j - i + 1 > ones)
        {

            while (j - i + 1 > ones)
            {
                if (nums[i % n] == 0)
                    zeroCnt--;
                i++;
            }
            ans = min(ans, zeroCnt);
        }

        j++;
    }

    return ans;
}
int main()
{

    vector<int> tc1 = {0, 1, 0, 1, 1, 0, 0};
    cout << "tc1 = " << minSwaps(tc1) << endl;

    return 0;
}