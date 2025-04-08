#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getHCF(int a, int b)
{
    if (b == 0)
        return a;

    int rem = a % b;
    return getHCF(b, rem);
}

int maxLength(vector<int> &nums)
{

    int left = 0, right = 0, ans = INT_MIN, lcm = 1, prod = 1;
    int n = nums.size();

    while (right < n)
    {
        prod *= nums[right];

        if (right - left + 1 < 2)
            right++;

        else
        {
            int gcd = nums[left];
            gcd = getHCF(nums[right], gcd);
            lcm = prod / gcd;

            if (prod == gcd * lcm)
                ans = max(ans, right - left + 1);
        }

        right++;
    }

    return ans;
}

int main()
{

    return 0;
}