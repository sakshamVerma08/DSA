#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, const char &ch)
{

    vector<string> result;
    string buffer;

    for (char c : s)
    {

        // If c is a delimiter, then check if current_token is empty or not.
        // If it's not empty, then push it in the result array, that marks the 'completion of a word'. (successfully split on the delimiter)

        // If it's empty, then don't push it.

        if (c == ch)
        {

            if (!buffer.empty())
            {
                result.push_back(buffer);
                buffer.clear();
            }
        }

        else
        {
            buffer.push_back(c);
        }
    }

    // We will scan the last word outside the loop. Becuase the last word will never end with a delimiter, so if we don't scan
    // it outside the loop, it might go un-scanned.

    if (!buffer.empty())
        result.push_back(buffer);

    return result;
}

string reverseWords(string s)
{
    vector<string> words = split(s, ' ');
    string res;

    int n = words.size();

    for (auto it = words.rbegin(); it != words.rend(); it++)
    {

        if (res.size() != 0)
        {
            res += ' ';
            res += (*it);
        }

        else
            res += (*it);
    }

    return res;
}

string reverseWords2(string s)
{

    reverse(s.begin(), s.end());

    int i = 0;
    int left = 0;
    int right = 0;

    int n = s.size();

    while (i < n)
    {

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        if (i == n)
            break;

        while (i < n && s[i] != ' ')
        {

            s[right] = s[i];
            i++;
            right++;
        }

        reverse(s.begin() + left, s.begin() + right);
        s[right] = ' ';
        right++;
        left = right;
        i++;
    }

    s.resize(right - 1);
    return s;
}
int main()
{

    string s1 = "saksham verma";
    string s2 = " saksham verma  ";
    string s3 = "   saksham is a boy    ";

    cout << "ans1 = " << reverseWords2(s1) << endl;
    cout << "ans2 = " << reverseWords2(s2) << endl;
    cout << "ans3 = " << reverseWords2(s3) << endl;

    return 0;
}