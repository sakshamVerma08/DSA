#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int> &nums)
{
    int zeroCnt = 0;
    int ans = 0;
    int i = 0, j = 0;

    while (j < nums.size())
    {

        if (nums[j] == 0)
            zeroCnt++;

        if (zeroCnt > 1)
        {
            // shrink the window
            if (nums[i] == 0)
                zeroCnt--;

            i++;
            ans = max(ans, j - i);
            j++;
        }

        else if (zeroCnt == 1)
        {
            ans = max(ans, j - i);
            j++;
        }

        else
            j++;
    }

    if (ans == 0)
        ans = max(ans, j - i - 1);

    return ans;
}

int main()
{

    return 0;
}