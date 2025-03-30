#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    int len = s.size();
    int left = 0, right = 0;
    int total = 0;

    vector<int> freq(3);

    while (right < len)
    {
        char tmp = s[right];
        if (tmp == 'a')
            freq[0]++;

        else if (tmp == 'b')
            freq[1]++;

        else
            freq[2]++;

        while (freq[0] != 0 && freq[1] != 0 && freq[2] != 0)
        {

            total += (len - right);
            char x = s[left];
            if (x == 'a')
                freq[0]--;

            else if (x == 'b')
                freq[1]--;

            else
                freq[2]--;

            left++;
        }

        right++;
    }

    return total;
}

int main()
{

    string s1 = "abcabc";
    cout << "tc1 = " << numberOfSubstrings(s1) << endl;

    return 0;
}