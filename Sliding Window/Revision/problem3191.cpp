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

int minOperations(vector<int> &nums)
{
    int cnt = 0;

    int left = 0, right = 0;
    int n = nums.size();

    while (right < n)
    {

        if (right - left + 1 < 3)
        {
            right++;
            continue;
        }

        else if (right - left + 1 > 3)
        {
            left++;

            if (nums[left] == 0)
            {
                nums[left] = !nums[left];
                nums[left + 1] = !nums[left + 1];
                nums[right] = !nums[right];
                cnt++;
            }
        }

        else
        {
            if (nums[left] == 0)
            {
                nums[left] = !nums[left];
                nums[left + 1] = !nums[left + 1];
                nums[right] = !nums[right];
                cnt++;
            }
        }

        right++;
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum == nums.size())
        return cnt;

    return -1;
}
int main()
{

    return 0;
}