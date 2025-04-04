#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countSubstringsWithoutRepeatingCharacters(string s)
{

    unordered_map<char, int> freq;
    int cnt = 0;
    int i = 0, j = 0;
    while (j < s.size())
    {
        // Sliding window logic

        freq[s[j]]++;

        // Shrink the window until only one ocurrence of that character is left in the window.
        while (freq[s[j]] > 1)
        {
            freq[s[i]]--;
            if (freq[s[i]] == 0)
                freq.erase(s[i]);
            i++;
        }

        cnt += (j - i + 1);

        j++;
    }

    return cnt;
}

int main()
{

    string tc1 = "abcd";
    cout << "tc1 = " << countSubstringsWithoutRepeatingCharacters(tc1) << endl;
    string tc2 = "abcdab";
    cout << "tc2 = " << countSubstringsWithoutRepeatingCharacters(tc2) << endl;
    string tc3 = "abbb";
    cout << "tc3 = " << countSubstringsWithoutRepeatingCharacters(tc3) << endl;

    return 0;
}