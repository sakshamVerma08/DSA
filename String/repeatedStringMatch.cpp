#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string a, string b)
{

    int count = 0;
    string ans = "";

    while (ans.size() < b.size())
    {

        ans += a;
        count++;
    }

    if (ans.find(b) != string::npos)
    {
        return count;
    }

    ans += a;
    count++;

    if (ans.find(b) != string::npos)
    {
        return count;
    }

    return -1;
}
int main()
{

    string a1 = "abcd";
    string b1 = "dabcda";

    cout << "ans1 = " << repeatedStringMatch(a1, b1) << endl;

    string a2 = "abcdef";
    string b2 = "abcdefabcdef";

    cout << "ans2 = " << repeatedStringMatch(a2, b2) << endl;

    return 0;
}