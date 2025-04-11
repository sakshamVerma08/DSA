#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Brute force solution
// time complexity :O(k . n)
// space complexity : O(n)
vector<int> decrypt(vector<int> &code, int k)
{
    vector<int> res(code.size(), 0);

    for (int i = 0; i < code.size(); i++)
    {

        if (k == 0)
            return res;

        else if (k > 0)
        {
            for (int j = i + 1; j <= i + k; j++)
            {
                res[i] += code[j % code.size()];
            }
        }

        else
        {
            for (int j = i - abs(k); j < i; j++)
            {
                res[i] += code[(j + code.size()) % code.size()];
            }
        }
    }

    return res;
}

// Optimized Solution using Sliding Window Approach

vector<int> decrypt(vector<int> &code, int k)
{
    int n = code.size();
    vector<int> res(n, 0);

    if (k == 0)
        return res;

    int start, end;

    if (k > 0)
    {
        start = 1;
        end = k;
    }

    else
    {
        start = n - k;
        end = n - 1;
    }

    int initSum = 0;

    for (int i = start; i <= end; i++)
    {
        initSum += code[i];
    }

    res[0] = initSum;

    for (int i = 1; i < n; i++)
    {
        initSum -= code[(start % n)];
        initSum += code[(end + 1) % n];
        res[i] = initSum;
        start++;
        end++;
    }

    return res;
}
int main()
{

    return 0;
}