#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxDepth(string s)
{
    stack<char> st;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(')
            st.push(s[i]);

        if (s[i] == ')')
        {

            if (ans < st.size())
                ans = st.size();

            st.pop();
        }
    }

    return ans;
}

int maxDepth2(string s)
{
    int ans = 0, count = 0;

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(')
            count++;

        if (s[i] == ')')
        {

            ans = max(ans, count);
            count--;
        }
    }

    return ans;
}
int main()
{

    string s1 = "(1 + (2*3) +  ((8)/4) ) + 1";

    cout << "ans= " << maxDepth2(s1) << endl;

    return 0;
}