#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string temp = "";
    stack<string> st;
    int i = 0, n = s.size();

    while (i < n && s[i] == ' ')
    {
        i++;
    }

    while (i < n)
    {
        if (s[i] != ' ')
        {
            temp += s[i];
        }

        else
        {

            if (temp != "")
            {
                st.push(temp);
                temp = "";
            }
        }

        if (i == n - 1)
        {

            if (temp != "")
                st.push(temp);
        }

        i++;
    }

    string ans = "";

    while (!st.empty())
    {

        string top = st.top();
        st.pop();

        ans += top;

        if (!st.empty())
            ans += ' ';
    }
    return ans;
}

string reversewords2(string &s)
{

    reverse(s.begin(), s.end());
    string ans = "", word = "";
    int i = 0, n = s.size();

    while (i < n)
    {

        word = "";

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.size() > 0)
            ans += " " + word;

        i++;
    }

    return ans.substr(1);
}
int main()
{

    string s1 = "  hello world  ";
    string s2 = "the sky is blue";
    string s3 = "    saksham  verma    ";

    cout << "ans = " << reversewords2(s1) << endl;
    cout << "ans = " << reversewords2(s2) << endl;
    cout << "ans = " << reversewords2(s3) << endl;

    return 0;
}