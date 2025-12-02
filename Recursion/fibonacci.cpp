#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{

    if (n == 0)
        return 0;

    else if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int fib2(int n)
{

    vector<long long> dp(n + 1, -1);

    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return n;
    }

    else
    {

        if (dp[n] != -1)
            return dp[n];

        else
        {

            long long ans = fib(n - 1) + fib(n - 2);
            dp[n] = ans;
            return ans;
        }
    }
}
int main()
{

    // 0 0 1 1 2 3 5 8 13 21.....

    int n1 = 5;
    int n2 = 8;

    cout << "ans1 = " << fib2(n1) << endl;
    cout << "ans2 = " << fib2(n2) << endl;

    return 0;
}