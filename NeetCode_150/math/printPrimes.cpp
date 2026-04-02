#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
    }

    vector<int> preCompute(int n)
    {
        vector<int> v(n + 1, 1);

        for (int i = 2; i < sqrt(v.size()); i++)
        {

            if (v[i] == 1)
            {
                int mult = i, idx;
                while (i * mult <= n)
                {
                    idx = i * mult;
                    v[idx] = 0;
                    mult++;
                }
            }
        }
        return v;
    }

    void printPrimes(int n)
    {
        auto primes = preCompute(n);
        for (int i = 2; i < primes.size(); i++)
        {
            if (primes[i] == 1)
                cout << i << " ";
        }
        cout << endl;
        return;
    }
};
int main()
{
    int n1 = 30;
    int n2 = 60;
    int n3 = 5 * 1e6;

    Solution s;
    s.printPrimes(n1);

    return 0;
}