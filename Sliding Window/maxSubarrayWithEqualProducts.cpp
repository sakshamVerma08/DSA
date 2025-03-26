#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    int ans = (a * b) / gcd(a, b);
    return ans;
}

// This will throw a 'memory overflow error' for line product. This approach can't be done using this method. Because it throws an error even for 'long long int'.
int maxLength(vector<int> &nums)
{
    long ans = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {

        for (int j = i + 1; j < nums.size(); j++)
        {

            int x = nums[i];
            int y = 1;
            long long int product = 1;

            for (int k = i; k <= j; k++)
            {
                x = gcd(x, nums[k]);
                y = lcm(y, nums[k]);
                product *= nums[k];
            }

            if (product == x * y)
            {
                if (j - i + 1 > ans)
                    ans = j - i + 1;
            }
        }
    }

    return ans;
}

int maxLength(vector<int> &nums)
{

    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        long long int prod = 1;
        int x = nums[i];
        int y = nums[i];

        for (int j = i; j < nums.size(); j++)
        {

            if (j >= i)
            {
                x = gcd(x, nums[j]);
                y = lcm(y, nums[j]);

                if (prod > LLONG_MAX / nums[j])
                    break;

                prod *= nums[j];
            }

            if (prod == x * y)
            {

                if (maxLength < j - i + 1)
                    maxLength = j - i + 1;
            }
        }
    }

    return maxLength;
}

int main()
{

    return 0;
}