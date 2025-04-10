#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(N)
// space complexity : O(N)
int reverseDegree(string s)
{
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    unordered_map<char, int> mpp;

    int val = 26;

    for (auto elem : alphabets)
    {
        mpp[elem] = val;
        val -= 1;
    }

    int ans = 0;
    int idx = 1;
    for (auto &elem : s)
    {
        ans += (mpp[elem] * idx);
        idx++;
    }

    return ans;
}

// time complexity :O(N)
// space complexity : O(1)
int reverseDegree2(string s)
{

    long int res = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int k = s[i] - 97;
        res += (26 - k) * (i + 1);
    }

    return res;
}
int main()
{

    return 0;
}