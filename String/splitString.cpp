#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, const char &c)
{

    vector<string> result;
    string current;

    for (auto character : s)
    {

        if (character == c)
        {
            // It is the delimiter. So we push the current token in the result, before checking whether it's empty
            // or not.

            if (!current.empty())
            {
                result.emplace_back(current);

                current.clear();
            }
        }

        else
        {
            // It's not a delimiter, then add it to the 'current' token.
            current.push_back(character);
        }
    }

    if (!current.empty())
        result.emplace_back(current);

    return result;
}

void printVector(vector<string> &arr)
{

    for (string s : arr)
    {
        cout << s << ",";
    }
    cout << endl;
}
int main()
{

    string s1 = "saksham verma";
    string s2 = " saksham verma is a boy ";
    vector<string> ans = split(s1, ' ');
    vector<string> ans2 = split(s2, ' ');

    printVector(ans);
    printVector(ans2);

    return 0;
}