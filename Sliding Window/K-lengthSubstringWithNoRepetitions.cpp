#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int problem1100(string s, int k)
{
    if (k > s.size())
        return 0;

    else if (k == 1)
        return s.size();

    unordered_map<char, int> mpp;
    int cnt = 0;

    int i = 0, j = 0;

    while (j < s.size())
    {

        mpp[s[j]]++;

        if (j - i + 1 > k)
        {
            // Window size has exceeded k

            mpp[s[i]]--;
            if (mpp[s[i]] == 0)
                mpp.erase(s[i]);

            i++;
        }

        if (j - i + 1 == k && mpp.size() == k)
            cnt++;

        j++;
    }

    return cnt;
}
int main()
{

    string tc1 = "havefunonleetcode";
    string tc2 = "abcdeffgh";
    int k1 = 5;
    int k2 = 3;

    cout << "tc1 = " << problem1100(tc1, k1) << endl;
    cout << "tc2 = " << problem1100(tc2, k2) << endl;

    return 0;
}