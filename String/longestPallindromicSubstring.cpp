#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s)
{

    int start = 0, end = s.size() - 1;

    while (start <= end)
    {

        if (s[start] != s[end])
            return false;

        else
        {
            start++;
            end--;
        }
    }

    return true;
}

string longestPalindrome(string s)
{

    if (s.size() == 1)
        return s;

    int n = s.size();
    string ans = "";

    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {

            string sub = s.substr(i, j - i + 1);
            if (isPallindrome(sub) && sub.size() > ans.size())
            {
                ans = sub;
            }
        }
    }

    return ans;
}

// *****************************
// *****************************

string longestPalindrome2(string s)
{

    string ans = "";
    int n = s.size();

    for (int i = 0; i < n; i++)
    {

        // Check for Odd Length Pallindromes.
        int l = i;
        int r = i;

        while (l >= 0 && r < n && s[l] == s[r])
        {

            if (r - l + 1 > ans.size())
            {
                ans = s.substr(l, r - l + 1);
            }

            l--;
            r++;
        }

        // Check for Even Length pallindromes.

        int left = i;
        int right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right])
        {

            if (right - left + 1 > ans.size())
                ans = s.substr(left, right - left + 1);

            left--;
            right++;
        }
    }

    return ans;
}
int main()
{

    string s1 = "babad";
    string s2 = "acdbbda";

    cout << "ans1 = " << longestPalindrome2(s1) << endl;
    cout << "ans2 = " << longestPalindrome2(s2) << endl;

    return 0;
}