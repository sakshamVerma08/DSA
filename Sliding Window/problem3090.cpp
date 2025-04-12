#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// time complexity : O(N)
// space complexity : O(N)
int maximumLengthSubstring(string s)
{
    int st = 0, end = 0;
    int maxi = INT_MIN;
    unordered_map<char, int> freq;
    int n = s.size();

    while (end < n)
    {
        freq[s[end]]++;

        while (freq[s[end]] == 3)
        {
            freq[s[st]]--;
            st++;
        }

        maxi = max(maxi, end - st + 1);
        end++;
    }
    return maxi;
}
int maximumLengthSubstring(string s)
{
    int st = 0, end = 0;
    int maxi = INT_MIN;
    int n = s.size();
    unordered_set<char> charSet;
    for (int i = 0; i < n; i++)
    {
        charSet.insert(s[i]);
    }
    unordered_map<char, int> freq;
    int flag;
    while (end < n)
    {
        flag = true;
        freq[s[end]]++;

        for (auto &elem : charSet)
        {
            if (freq[elem] > 2)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            maxi = max(maxi, end - st + 1);

        else
        {
            freq[s[st]]--;
            st++;
        }
        end++;
    }

    return maxi;
}

int main()
{

    return 0;
}