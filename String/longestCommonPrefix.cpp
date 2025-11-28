#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    string pref = strs[0];

    for (int i = 1; i < strs.size(); i++)
    {

        string temp = "";

        int idx = 0;
        int size = strs[i].size();

        for (int j = 0; j < size; j++)
        {

            if (idx == pref.size())
                break;

            if (pref[idx++] == strs[i][j])
                temp += strs[i][j];

            else
                break;
        }

        pref = temp;
    }

    return pref;
}

// TC) O(N x M) , N is number of strings, M is the min length of a string.

string longestCommonPrefix2(vector<string> &strs)
{
    sort(strs.begin(), strs.end());

    int idx = 0;
    string s1 = strs[0], s2 = strs[strs.size() - 1], ans = "";

    int size = s2.size();

    for (int j = 0; j < size; j++)
    {

        if (s1[idx++] == s2[j])
            ans += s2[j];

        else
            break;
    }

    return ans;
}

// TC O(N logN x M)

int main()
{

    vector<string> v1 = {"flow", "flower", "florida", "flowing"};
    vector<string> v2 = {"saksham", "abc", "sak"};

    string ans1 = longestCommonPrefix(v1);
    string ans2 = longestCommonPrefix2(v2);

    cout << "ans1 = " << ans1 << endl;
    cout << "ans2 = " << ans2 << endl;

    return 0;
}