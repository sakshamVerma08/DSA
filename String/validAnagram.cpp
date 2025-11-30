#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, int> sMapping, tMapping;

    for (int i = 0; i < s.size(); i++)
    {

        if (sMapping.find(s[i]) != sMapping.end())
        {
            sMapping[s[i]]++;
        }

        else
            sMapping[s[i]] = 1;
    }

    for (int i = 0; i < t.size(); i++)
    {

        if (tMapping.find(t[i]) != tMapping.end())
        {
            tMapping[t[i]]++;
        }

        else
            tMapping[t[i]] = 1;
    }

    for (int i = 0; i < s.size(); i++)
    {

        if (sMapping[s[i]] != tMapping[s[i]])
            return false;
    }

    return true;
}

bool isAnagram2(string s, string t)
{
    if (s.size() != t.size())
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] != t[i])
            return false;
    }

    return true;
}

bool isAnagram3(string s, string t)
{
    if (s.size() != t.size())
        return false;

    int freq[26] = {};

    for (int i = 0; i < s.size(); i++)
    {

        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); i++)
    {

        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {

        if (freq[i] != 0)
            return false;
    }

    return true;
}
int main()
{

    string s1 = "saksham";
    string s2 = "sakmhsa";

    cout << "ans = " << isAnagram3(s1, s2) << endl;

    return 0;
}