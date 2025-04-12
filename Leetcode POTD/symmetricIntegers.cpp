#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// time complexity : O(n * m)
// space complexity : O(1)
int countSymmetricIntegers(int low, int high)
{
    int ans, sum1, sum2;
    ans = 0;
    for (int i = low; i <= high; i++)
    {
        sum1 = 0;
        sum2 = 0;
        string s = to_string(i);
        if (s.size() % 2 != 0)
            continue;

        else
        {
            for (int j = 0; j < s.size() / 2; j++)
            {
                sum1 += (s[j] - '0');
            }

            for (int j = s.size() / 2; j < s.size(); j++)
            {
                sum2 += (s[j] - '0');
            }

            if (sum1 == sum2)
                ans += 1;
        }
    }

    return ans;
}