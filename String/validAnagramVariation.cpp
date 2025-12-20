// In this variation, I will try to write the code for the following cases of the 'Valid Anagram' question on Leetcode:
// Where strings can contain both lowercase and uppercase Characters. (use single hash array ).
// Where strings can contain unicode characters.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// only for numbers, uppercase & lowercase letters.
bool validAnagram1(string s, string t)
{
    if (s.size() != t.size())
        return false;

    vector<int> hashArray(256, 0);

    for (int i = 0; i < s.size(); i++)
    {

        hashArray[s[i] - (unsigned char)s[i]] += 1;
        hashArray[t[i] - (unsigned char)t[i]] -= 1;
    }

    for (int i = 0; i < 256; i++)
    {

        if (hashArray[i] != 0)
            return false;
    }

    return true;
}

int main()
{

    // false
    string s = "abc123";
    string t = "321cba";
    // Output: true

    string s2 = "!@#$";
    string t2 = "$#@!";

    string s3 = "Hello, World!";
    string t3 = "dlroW ,olleH!";

    cout
        << "ans1 = " << validAnagram1(s, t) << endl;
    cout << "ans2 = " << validAnagram1(s2, t2) << endl;
    cout << "ans3 = " << validAnagram1(s3, t3) << endl;

    return 0;
}
