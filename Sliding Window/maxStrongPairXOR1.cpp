#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(N^2)
// space complexity : O(1)
int maximumStrongPairXor(vector<int> &nums)
{

    int maxXor = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        for (int j = i; j < nums.size(); j++)
        {

            if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j]))
            {

                maxXor = max(maxXor, nums[i] ^ nums[j]);
            }
        }
    }

    return maxXor;
}


int main()
{

    return 0;
}