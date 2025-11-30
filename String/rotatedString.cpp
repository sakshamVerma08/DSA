#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void shift(string &s)
{

    char temp = s[0];

    for (int i = 1; i < s.size(); i++)
    {

        s[i - 1] = s[i];
    }

    s[s.size() - 1] = temp;
}
bool rotateString(string s, string goal)
{

    for (int i = 0; i < s.size(); i++)
    {

        shift(s);

        if (s == goal)
            return true;
    }

    return false;
}

bool rotateString2(string s, string goal)
{

    if (s.size() != goal.size())
        return false;

    string concatenatedString = s + s;

    return concatenatedString.find(goal) < concatenatedString.size();
}

int main()
{

    return 0;
}