#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC) O(2n) = O(n)
// SC) O(2n) = O(n)
string removeOuterParentheses1(string s)
{

    stack<int> st;
    string result = "";

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(')
            st.push(i);

        else
        {

            if (st.size() == 1)
            {
                // If the size of stack is equal to 1, this means that only one '(' is left in the stack (the index
                // of that character), so we can consider it as the outermost paranthesis.
                // So we replace the outermost paranthesis, both opening and closing paratheses with a '*', and re-
                // construct the result string without the '*'.

                s[i] = '*';
                s[st.top()] = '*';
            }

            st.pop();
        }
    }

    for (char ch : s)
    {

        if (ch != '*')
            result += ch;
    }

    return result;
}
// TC) O(n)
// SC) O(n) (if result is included)
string removeOuterParentheses2(string s)
{

    // Question meaning---> We're asked to remove the outermost paranthesis from all the 'valid' segments of the
    // string s

    // If we can somehow keep track of the no. of '(' and ')', then we can identify which paranthesis are the
    // outermost paranthesis, and hence remove them.

    int count = 0;
    string result = "";

    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == '(')
        {

            if (count > 0)
                result += '(';

            count++;
        }

        else if (s[i] == ')')
        {
            count--;

            if (count > 0)
                result += ')';
        }
    }

    return result;
}
int main()
{

    string s1 = "(()())(())";
    string s2 = "(()())";

    cout << "ans = " << removeOuterParentheses1(s1) << endl;
    cout << "ans2 = " << removeOuterParentheses1(s2) << endl;

    return 0;
}