#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s)
{

    int i = 0, n = s.size(), sign = 1;
    long long result = 0;
    // Skippin leading whitespaces first.

    while (i < n && s[i] == ' ')
    {
        i++;
    }

    // Checking the sign

    if (i < n && (s[i] == '-' || s[i] == '+'))
    {

        sign = (s[i] == '-' ? -1 : 1);
        i++;
    }

    // Reading the digits and converting them to desired numbers.

    while (i < n && s[i] >= '0' && s[i] <= '9')
    {

        result = result * 10 + (s[i] - '0');

        // Check for overflow at each step
        if (result * sign > INT_MAX)
            return INT_MAX;
        else if (result * sign < INT_MIN)
            return INT_MIN;

        i++;
    }

    return result * sign;
}
int main()
{

    string s1 = "   -056";
    string s2 = "1337c037";

    cout << "ans1 = " << myAtoi(s1) << endl;
    cout << "ans2 = " << myAtoi(s2) << endl;

    return 0;
}