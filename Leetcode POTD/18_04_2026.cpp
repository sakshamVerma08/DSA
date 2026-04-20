#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(int n)
    {
        bool isLeading = true;
        int res = 0;

        while (n)
        {
            int digit = n % 10;
            // (LeetDuck) This 'continue' skips reducing 'n', so 'n' never changes when leading zero.
            if (digit == 0 && isLeading)
            {
                n /= 10;
                continue;
            }
            isLeading = false;
            res = (res * 10) + digit;
            n /= 10;
        }
        return res;
    }

public:
    Solution()
    {
    }
    int mirrorDistance(int n)
    {
        return abs(n - helper(n));
    }
};

int main()
{
    int n = 25;
    Solution *s = new Solution();
    cout << "ans1 = " << s->mirrorDistance(n) << endl;

    return 0;
}