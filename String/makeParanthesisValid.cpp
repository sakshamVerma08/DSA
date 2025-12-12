#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minAddToMakeValid(string s)
{

    if (s.size() == 1)
        return 1;

    stack<char> st;
    int count = 0, n = s.size();

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '(')
            st.push(s[i]);

        else
        {

            if (st.empty())
                count++;

            else
                st.pop();
        }
    }

    return st.size() + count;
}

int minAddToMakeValid2(string s)
{

    if (s.size() == 1)
        return 1;

    int ans = 0, count = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '(')
            count += 1;

        else
        {

            if (count == 0)
                ans += 1;

            else
                count -= 1;
        }
    }

    return count + ans;
}

int main()
{

    string s1 = "(((";
    string s2 = ")))";
    string s3 = "()))((";

    cout << "ans1 = " << minAddToMakeValid(s1) << endl
         << "ans2 = " << minAddToMakeValid2(s2) << endl
         << "ans3 = " << minAddToMakeValid2(s3) << endl;

    return 0;
}