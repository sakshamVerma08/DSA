#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int romanToInt(string s)
{
    stack<char> st;
    unordered_map<char, int> mp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {

        if (!st.empty())
        {

            if (mp[s[i]] <= mp[st.top()])
            {
                ans += mp[s[i]];
                st.push(s[i]);
            }

            else
            {

                int temp = mp[s[i]] - 2 * mp[st.top()];
                ans += temp;
                st.push(s[i]);
            }
        }

        else
        {
            ans += mp[s[i]];
            st.push(s[i]);
        }
    }

    return ans;
}

int romanToInt2(string s)
{
    unordered_map<char, int> mp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int ans = 0;
    char prev = '*';

    for (int i = 0; i < s.size(); i++)
    {

        if (prev != '*')
        {

            if (mp[s[i]] <= mp[prev])
            {
                ans += mp[s[i]];
                prev = s[i];
            }

            else
            {

                int temp = mp[s[i]] - 2 * mp[prev];
                ans += temp;
                prev = s[i];
            }
        }

        else
        {
            ans += mp[s[i]];
            prev = s[i];
        }
    }

    return ans;
}
int main()
{

    string s1 = "III";
    string s2 = "MCMXCIV";

    cout << "ans1 = " << romanToInt(s1) << endl;
    cout << "ans2 = " << romanToInt(s2) << endl;

    return 0;
}