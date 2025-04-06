#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int> &nums)
{
    int count = 0;

    int j = 2;

    while (j < nums.size())
    {

        if (nums[j - 2] == 0)
        {
            count++;
            nums[j - 2] = !nums[j - 2];
            nums[j - 1] = !nums[j - 1];
            nums[j] = !nums[j];
        }
        j++;
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum == nums.size())
        return count;

    else
        return -1;
}
int main()
{

    return 0;
}