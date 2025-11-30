#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> ST, TS;

    for (int i = 0; i < s.size(); i++)
    {

        if (ST.count(s[i]) && ST[s[i]] != t[i])
            return false;

        else if (TS.count(t[i]) && TS[t[i]] != s[i])
            return false;

        else
        {
            ST[s[i]] = t[i];
            TS[t[i]] = s[i];
        }
    }

    return true;
}

bool isIsomorphic2(string s, string t)
{

    vector<int> hash_ST(256, -1);
    vector<int> hash_TS(256, -1);

    for (int i = 0; i < s.size(); i++)
    {

        if (hash_ST[i] != -1 && hash_ST[s[i]] != t[i])
            return false;

        else if (hash_TS[t[i]] != -1 && hash_TS[t[i]] != s[i])
            return false;

        else
        {
            hash_ST[s[i]] = t[i];
            hash_TS[t[i]] = s[i];
        }
    }

    return true;
}

int main()
{

    string s1 = "foo";
    string s2 = "bar";

    cout << "ans1 = " << isIsomorphic(s1, s2) << endl;
    cout << "ans2 = " << isIsomorphic2(s1, s2) << endl;

    return 0;
}